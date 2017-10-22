TOMUSLIB = ../tomuslib/
INCLUDES = $(TOMUSLIB)/inc/
TOMUSLIB_FILE = $(TOMUSLIB)/inc/libtomus.a
CC = g++

BUILD_DIRECTORY = build

PROJECT_NAME = int_sqrt

SOURCES = $(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

default ($PROJECT_NAME): $(OBJECTS)
	@echo Creating executable $(PROJECT_NAME).out
	@cd $(BUILD_DIRECTORY) && $(CC) $(OBJECTS) -o $(PROJECT_NAME).out

.cpp.o: setup
	@echo Compiling file $<
	@$(CC) -c $< -o $(BUILD_DIRECTORY)/$@

setup: clean
	@mkdir $(BUILD_DIRECTORY)

clean:
	@echo Cleaning project
	@$(RM) -rf $(BUILD_DIRECTORY)

run: default
	@echo Running project $(PROJECT_NAME) 
	@echo
	@echo
	@./$(BUILD_DIRECTORY)/$(PROJECT_NAME).out

test: default
	@nosetests