#include "unity.h"
#include <stdint.h>
#include <stdio.h>

#define SS_FORMAT_MASK 0x01
#define SS_FORMAT_INDEX 0
#define SS_SHORT_LEN_MASK 0x3E
#define SS_SHORT_LEN_INDEX 0
#define SS_SHORT_LEN_OFFSET 1
#define SS_SHORT_PROPERTY_ID_LOW_MASK 0xF0
#define SS_SHORT_PROPERTY_ID_LOW_INDEX 0
#define SS_SHORT_PROPERTY_ID_LOW_OFFSET 4
#define SS_SHORT_PROPERTY_ID_HIGH_INDEX 1
#define SS_SHORT_PROPERTY_OFFSET 2

#define SS_LONG_LEN_MASK 0xFE
#define SS_LONG_LEN_INDEX 0
#define SS_LONG_LEN_OFFSET 1
#define SS_LONG_PROPERTY_ID_LOW_INDEX 1
#define SS_LONG_PROPERTY_ID_HIGH_INDEX 2
#define SS_LONG_PROPERTY_OFFSET 3

#define PRESENCE_DETECTED_PROPERTY_ID 0x004D
#define PRESENT_AMBIENT_LIGHT_LEVEL 0x004E

int printf_calls  = 0;
int println_calls = 0;

void println(const char * string)
{
  printf("%s\n", string);
  println_calls++;
}

void MeshInternal_ProcessSensorStatus(uint8_t * payload, size_t len);
void MeshInternal_ProcessSensorStatusShort(uint8_t * payload, size_t len);
void MeshInternal_ProcessSensorStatusLong(uint8_t * payload, size_t len);
void MeshInternal_ProcessSensorProperty(uint16_t property_id, uint8_t * payload, size_t len);
void MeshInternal_ProcessPresenceDetected(uint8_t * payload, size_t len);
void MeshInternal_ProcessPresentAmbientLightLevel(uint8_t * payload, size_t len);

void MeshInternal_ProcessSensorStatus(uint8_t * payload, size_t len)
{
  if(!len >= 1)
  {
    println("Received empty sensor status message");
    return;
  }

  if(0 == payload[SS_FORMAT_INDEX] & SS_FORMAT_MASK)
    MeshInternal_ProcessSensorStatusShort(payload, len);
  else
    MeshInternal_ProcessSensorStatusLong(payload, len);
}

void MeshInternal_ProcessSensorStatusShort(uint8_t * payload, size_t len)
{
  size_t message_len = (payload[SS_SHORT_LEN_INDEX] & SS_SHORT_LEN_MASK) >> SS_SHORT_LEN_OFFSET;

  uint16_t property_id =
      (payload[SS_SHORT_PROPERTY_ID_LOW_INDEX] & SS_SHORT_PROPERTY_ID_LOW_MASK) >>
      SS_SHORT_PROPERTY_ID_LOW_OFFSET;
  property_id |= payload[SS_SHORT_PROPERTY_ID_HIGH_INDEX] << 8;

  MeshInternal_ProcessSensorProperty(
      property_id, payload + SS_SHORT_PROPERTY_OFFSET, message_len - SS_SHORT_PROPERTY_OFFSET);
}

void MeshInternal_ProcessSensorStatusLong(uint8_t * payload, size_t len)
{
  size_t message_len = (payload[SS_LONG_LEN_INDEX] & SS_LONG_LEN_MASK) >> SS_LONG_LEN_OFFSET;

  uint16_t property_id = payload[SS_LONG_PROPERTY_ID_LOW_INDEX];
  property_id |= payload[SS_LONG_PROPERTY_ID_HIGH_INDEX] << 8;

  MeshInternal_ProcessSensorProperty(
      property_id, payload + SS_LONG_PROPERTY_OFFSET, message_len - SS_LONG_PROPERTY_OFFSET);
}

void MeshInternal_ProcessSensorProperty(uint16_t property_id, uint8_t * payload, size_t len)
{
  switch(property_id)
  {
    case PRESENCE_DETECTED_PROPERTY_ID:
    {
      MeshInternal_ProcessPresenceDetected(payload, len);
      break;
    }
    case PRESENT_AMBIENT_LIGHT_LEVEL:
    {
      MeshInternal_ProcessPresentAmbientLightLevel(payload, len);
      break;
    }
    default:
    {
      println("Invalid property id");
    }
  }
}

void MeshInternal_ProcessPresenceDetected(uint8_t * payload, size_t len)
{
  if(len != 1)
  {
    println("Received too short or too long sensor status message");
    return;
  }

  uint8_t value = payload[0];

  if(value > 1)
  {
    println("Received sensor status message, presence detected with prohibited value");
  }
  else
  {
    printf("Received sensor status message, presence detected with value of: %d\n", value);
  }
}

#define PRESENT_AMBIENT_LIGHT_LEVEL_MAX 16777214
#define PRESENT_AMBIENT_LIGHT_LEVEL_UNKNOWN 0xFFFFFF

void MeshInternal_ProcessPresentAmbientLightLevel(uint8_t * payload, size_t len)
{
  if(len != 3)
  {
    println("Received too short or too long sensor status message");
    return;
  }

  uint32_t value = payload[0];
  value |= payload[1] << 8;
  value |= payload[2] << 8;

  if(value > PRESENT_AMBIENT_LIGHT_LEVEL_MAX && value != PRESENT_AMBIENT_LIGHT_LEVEL_UNKNOWN)
  {
    println("Received sensor status message, present ambient light level with prohibited value");
  }
  else if(value == PRESENT_AMBIENT_LIGHT_LEVEL_UNKNOWN)
  {
    println("Received sensor status message, present ambient light level with unknown value");
  }
  else
  {
    printf(
        "Received sensor status message, present ambient light level with value of: %d\n", value);
  }
}

void test_test(void)
{
  uint8_t message[3] = {0};

  message[0] = 0;
  message[0] |= 1 << 1;
  message[0] |= (0x4D & 0x0F) << 4;
  message[1] = (0x4D & 0xF0) >> 4;
  message[2] = 1;

  MeshInternal_ProcessSensorStatus(message, 3);


  TEST_ASSERT_EQUAL(0, println_calls);
  TEST_ASSERT_EQUAL(1, printf_calls);
}