add_library               (unity STATIC unity.c)
target_include_directories(unity PUBLIC ${CMAKE_CURRENT_LIST_DIR})

set(UNITY_SCRIPTS ${CMAKE_CURRENT_LIST_DIR}/unity_scripts PARENT_SCOPE)

function(createTest TEST_NAME TEST_SRC)

    add_custom_command    (OUTPUT ${TEST_NAME}_runner.cpp
                           COMMAND ruby ${UNITY_SCRIPTS}/generate_test_runner.rb ${TEST_SRC} ${TEST_NAME}_runner.cpp)

    add_executable        (${TEST_NAME} ${TEST_SRC}
                                                 ${TEST_NAME}_runner.cpp)
    target_link_libraries (${TEST_NAME} unity)

    add_dependencies      (check        ${TEST_NAME})
    add_test              (${TEST_NAME} ${TEST_NAME})

endfunction()