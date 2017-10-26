CC = g++
UNITY = ../unit$(TEST_DIR)/unity
INCLUDES = inc/

PROJECT_NAME = libtomus

BUILD_DIR = build
SOURCE_DIR = src
TEST_DIR = tests
TEST_BUILD_DIR = tests/build

SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
_OBJECTS = $(patsubst $(SOURCE_DIR)%, $(BUILD_DIR)%, $(SOURCES))
OBJECTS = $(patsubst %.cpp, %.o, $(_OBJECTS))

TEST_CASES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_RUNNERS = $(patsubst $(TEST_DIR)/%.cpp, $(TEST_BUILD_DIR)/%_runner.cpp, $(TEST_CASES))
TEST_RUNNERS_EXE = $(patsubst $(TEST_BUILD_DIR)/%_runner.cpp, $(TEST_BUILD_DIR)/%_runner, $(TEST_RUNNERS))

UNITY_SCRIPTS = $(UNITY)/auto
UNITY_SOURCES = $(wildcard $(UNITY)/src/*.c)
UNITY_INCLUDE = $(UNITY)/src

.PHONY: default setup clean test unit_test python_test

default ($PROJECT_NAME): $(OBJECTS)
	@echo Creating library $(PROJECT_NAME).a
	@$(AR) rcs $(BUILD_DIR)/$(PROJECT_NAME).a $(OBJECTS)

$(BUILD_DIR)/%.o: src/%.cpp $(BUILD_DIR)
	@echo Compiling file $<
	@$(CC) -c $< -o $@ -I $(INCLUDES)

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

clean:
	@echo Cleaning project
	@$(RM) -rf $(BUILD_DIR)
	@$(RM) -rf $(TEST_BUILD_DIR)

test: default unit_test python_test

python_test:
	@nosetests

unit_test: $(TEST_RUNNERS_EXE)

$(TEST_BUILD_DIR)/%_runner: $(TEST_BUILD_DIR)/%_runner.cpp $(TEST_DIR)/%.cpp
	@$(CC) $^ $(UNITY_SOURCES) -o $@ -I $(INCLUDES) -I $(UNITY_INCLUDE) -I $(SOURCE_DIR)
	@./$@

.PRECIOUS: $(TEST_BUILD_DIR)/%_runner.cpp
$(TEST_BUILD_DIR)/%_runner.cpp: $(TEST_DIR)/%.cpp $(TEST_BUILD_DIR)
	@ruby $(UNITY_SCRIPTS)/generate_test_runner.rb $< $@

$(TEST_BUILD_DIR):
	@mkdir $(TEST_BUILD_DIR)

