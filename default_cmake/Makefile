PROJECT_NAME = "main"

MK := mkdir
RM := rm -rf
MV := mv -f

SOURCE_PATH = "$(shell pwd)/source"
TEST_PATH = "$(shell pwd)/tests"
BUILD_SOURCE_PATH = "$(shell pwd)/build/debug"
BUILD_TEST_PATH = "$(shell pwd)/build/tests"
GENERATOR ?= Eclipse CDT4 - Unix Makefiles

DEBUG_PARAMS    = -DCMAKE_BUILD_TYPE=DEBUG      $(SOURCE_PATH) -DCMAKE_TOOLCHAIN_FILE=${SOURCE_PATH}/arm-none-eabi.cmake
RELEASE_PARAMS  = -DCMAKE_BUILD_TYPE=MINSIZEREL $(SOURCE_PATH) -DCMAKE_TOOLCHAIN_FILE=${SOURCE_PATH}/arm-none-eabi.cmake

.PHONY: default compile run tests help clean generate

default: help

compile: build/debug/${PROJECT_NAME}

generate: build/debug build/tests

build/debug:
	@ echo "Generating build system"
	@ $(MK) $(BUILD_SOURCE_PATH) && cd $(BUILD_SOURCE_PATH) && cmake -DPROJECT_NAME=$(PROJECT_NAME) $(SOURCE_PATH)

build/tests:
	@ echo "Generating test running system"
	@ $(MK) $(BUILD_TEST_PATH) && cd $(BUILD_TEST_PATH) && cmake -DPROJECT_NAME=$(PROJECT_NAME) $(TEST_PATH)

build/debug/${PROJECT_NAME}: build/debug
	@ echo "Building project"
	@ cd $(BUILD_SOURCE_PATH) && make -j

run: compile
	@ echo "Running project"
	@ cd $(BUILD_SOURCE_PATH)g && ./$(PROJECT_NAME) && echo ""

tests: build/tests
	@ echo "Running tests"
	@ cd $(BUILD_TEST_PATH) && make -j

clean:
	@ $(foreach dir,$(wildcard build/*), $(RM) $(dir))

help:
	@ echo "The following are some of the valid targets for this Makefile:"
	@ echo "... help"
	@ echo "... generate"
	@ echo "... compile"
	@ echo "... run"
	@ echo "... tests"
	@ echo "... clean"
	@ echo ""
	@ echo "To change cmake generator: GENERATOR=[\"Ninja\"|\"MSYS Makefiles\"|\"Unix Makefiles\"]"