cmake_minimum_required(VERSION 3.0.0)
project(NumberGuesser)

add_executable(${PROJECT_NAME} NumberGuesser.cpp)

# target_link_libraries(${PROJECT_NAME} SDL2main SDL2)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)