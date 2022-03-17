cmake_minimum_required(VERSION 3.14)

project(renderer)

add_subdirectory(glfw/)


add_executable(${PROJECT_NAME} main.cpp glad/glad.c)
target_include_directories(${PROJECT_NAME} PUBLIC glfw)  
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)  