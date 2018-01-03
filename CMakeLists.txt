cmake_minimum_required(VERSION 3.5)
project(wdi C CXX)
enable_testing()
include(ProcessorCount)
ProcessorCount(N)
add_custom_target(check COMMAND ctest --output-on-failure -j${N})
add_subdirectory(unitylib)

find_program(CMAKE_NOSE_EXECUTABLE nosetests)
if(NOT CMAKE_NOSE_EXECUTABLE)
  message(FATAL_ERROR "Could not find 'nosetests' command.")
endif(NOT CMAKE_NOSE_EXECUTABLE)

function(createTask TASK_NAME SOURCE_DIR TEST_DIR)

  file                  (GLOB SOURCES ${SOURCE_DIR}/*.c*)
  add_executable        (${TASK_NAME} ${SOURCES})
  target_link_libraries (${TASK_NAME} tomuslib)
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
      target_link_libraries(${TASK_NAME}_${TEST_NAME} tomuslib)
  endforeach()

  add_test(NAME ${TASK_NAME}_pythontest 
           COMMAND ${CMAKE_NOSE_EXECUTABLE} ${TEST_DIR}
           WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
  add_dependencies(check ${TASK_NAME})

endfunction()

macro(SUBDIRLIST result curdir)
  file(GLOB children RELATIVE ${curdir} ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      file(GLOB files ${curdir}/${child}/*)
      list(FIND files ${curdir}/${child}/CMakeLists.txt find_result)
      if(NOT find_result EQUAL -1)
        list(APPEND dirlist ${child})
      endif()
    endif()
  endforeach()
  set(${result} ${dirlist})
endmacro()

subdirlist(SUB_DIRS ${CMAKE_CURRENT_LIST_DIR})

list(REMOVE_ITEM SUB_DIRS unitylib)
foreach(subdir ${SUB_DIRS})
  add_subdirectory(${subdir})
endforeach()

add_custom_target(format ALL
                  COMMAND find ${CMAKE_CURRENT_LIST_DIR} -iname *.h -o -iname *.cpp -o -iname *.c | xargs clang-format -i -style=file
                  COMMENT "Formating code"
                  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})