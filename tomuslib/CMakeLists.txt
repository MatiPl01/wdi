file(GLOB SOURCES src/*.c*)
file(GLOB TEST_SOURCES tests/*.c*)
set(INCLUDES inc/)

add_library(tomuslib STATIC ${SOURCES})
target_include_directories(tomuslib PUBLIC ${INCLUDES})

foreach(test ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${test} NAME_WE)
  createTest(tomuslib_${TEST_NAME} ${test})
  target_include_directories(tomuslib_${TEST_NAME} PRIVATE ${INCLUDES})
endforeach()