cmake_minimum_required(VERSION 3.0.0)
project(2dgameengine)

set(LIB "./lib")

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(${LIB}/SFML-2.5.1)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /MD")
    # /MD (or /MDd for debug) 
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

include_directories(src/
                    ${LIB}/SFML-2.5.1/include)

# file(GLOB VENDORS_SOURCES ${SRC_C_FILES} ${SRC_H_FILES})
file(GLOB PROJECT_HEADERS src/*.h)
file(GLOB PROJECT_SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} 
                # ${VENDORS_SOURCES}
                ${PROJECT_SOURCES}
                ${PROJECT_HEADERS})

target_link_libraries(${PROJECT_NAME}
                        sfml-graphics
                        sfml-window
                        sfml-audio
                        sfml-system)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:sfml-graphics>
        $<TARGET_FILE:sfml-window>
        $<TARGET_FILE:sfml-system>
        $<TARGET_FILE:sfml-audio>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)
