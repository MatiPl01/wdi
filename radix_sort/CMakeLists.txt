set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/source)
set(TEST_DIR   ${CMAKE_CURRENT_LIST_DIR}/tests)
get_filename_component(TASK_NAME    ${CMAKE_CURRENT_LIST_DIR} NAME)

createTask(${TASK_NAME} ${SOURCE_DIR} ${TEST_DIR})