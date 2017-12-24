cmake_minimum_required(VERSION 3.5)
project(wdi C CXX)
enable_testing()
add_custom_target(check COMMAND ctest --output-on-failure -j)
add_subdirectory(unitylib)

find_program(CMAKE_NOSE_EXECUTABLE nosetests)
if(NOT CMAKE_NOSE_EXECUTABLE)
  message(FATAL_ERROR "Could not find 'nosetests' command.")
endif(NOT CMAKE_NOSE_EXECUTABLE)

function(createTask TASK_NAME SOURCE_DIR TEST_DIR)

  file                  (GLOB SOURCES ${SOURCE_DIR}/*.c*)
  add_executable        (${TASK_NAME} ${SOURCES})
  add_custom_command    (TARGET ${TASK_NAME} 
                         POST_BUILD COMMAND cp ${TASK_NAME} test_me)

  add_custom_target     (${TASK_NAME}_run 
                         COMMAND         ${TASK_NAME}
                         MAIN_DEPENDENCY ${TASK_NAME}
                         COMMENT         "Running ${TASK_NAME} now\n\n")

  file(GLOB TEST_SOURCES ${TEST_DIR}/*.c*)

  foreach(test ${TEST_SOURCES})
      get_filename_component(TEST_NAME ${test} NAME_WE)
      createTest(${TASK_NAME}_${TEST_NAME} ${test})
  endforeach()

  add_test(NAME ${TASK_NAME}_pythontest 
           COMMAND ${CMAKE_NOSE_EXECUTABLE} ${TEST_DIR}
           WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
  add_dependencies(check ${TASK_NAME})
  add_dependencies(${TASK_NAME} tomuslib)

endfunction()

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      FILE(GLOB files ${curdir}/${child}/*)
      list(FIND files ${curdir}/${child}/CMakeLists.txt find_result)
      if(NOT find_result EQUAL -1)
        LIST(APPEND dirlist ${child})
      endif()
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(SUB_DIRS ${CMAKE_CURRENT_LIST_DIR})

list(REMOVE_ITEM SUB_DIRS unitylib)
FOREACH(subdir ${SUB_DIRS})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()
