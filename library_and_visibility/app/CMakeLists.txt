cmake_minimum_required(VERSION 3.0.0)
project(app VERSION 0.1.0)

include_directories(../library)

add_executable(${PROJECT_NAME} MainApp.cpp MainApp.h)

target_link_libraries(${PROJECT_NAME} library)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:library>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)