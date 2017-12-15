cmake_minimum_required(VERSION 3.5)

project(${PROJECT_NAME} C CXX)

file(GLOB SOURCES "*.c*")

add_executable(${PROJECT_NAME} ${SOURCES})