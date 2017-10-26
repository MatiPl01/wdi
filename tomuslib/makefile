CC = g++
UNITY = ../unittests/unity
INCLUDES = inc/

BUILD_DIRECTORY = build

PROJECT_NAME = libtomus

SOURCES = $(wildcard src/*.cpp)
_OBJECTS = $(patsubst src%, build%, $(SOURCES))
OBJECTS = $(patsubst %.cpp, %.o, $(_OBJECTS))

TEST_CASES = $(wildcard tests/*.cpp)
TEST_RUNNERS = $(patsubst tests/%.cpp, tests/%_runner.cpp, $(TEST_CASES))
TEST_RUNNERS_EXE = $(patsubst tests/%_runner.cpp, tests/%_runner, $(TEST_RUNNERS))

UNITY_SCRIPTS = $(UNITY)/auto

.PHONY: default setup clean test unit_tests python_tests

default ($PROJECT_NAME): $(OBJECTS)
	@echo Creating library $(PROJECT_NAME).a
	@$(AR) rcs $(BUILD_DIRECTORY)/$(PROJECT_NAME).a $(OBJECTS)

$(BUILD_DIRECTORY)/%.o: src/%.cpp $(BUILD_DIRECTORY)
	@echo Compiling file $<
	@$(CC) -c $< -o $@ -I $(INCLUDES)

$(BUILD_DIRECTORY):
	@mkdir $(BUILD_DIRECTORY)

clean:
	@echo Cleaning project
	@$(RM) -rf $(BUILD_DIRECTORY)
	@$(RM) $(TEST_RUNNERS) $(TEST_RUNNERS_EXE)

test: default unit_tests python_test

python_test:
	nosetests

unit_tests: $(TEST_RUNNERS_EXE)

tests/%_runner: tests/%_runner.cpp tests/%.cpp
	$(CC) $^ $(UNITY)/src/*.c -o $@ -I $(INCLUDES) -I $(UNITY)/src
	./$@

tests/%_runner.cpp: tests/%.cpp
	ruby $(UNITY_SCRIPTS)/generate_test_runner.rb $< $@

