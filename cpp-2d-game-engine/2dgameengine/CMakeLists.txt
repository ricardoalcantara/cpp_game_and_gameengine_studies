cmake_minimum_required(VERSION 3.0.0)
project(2dgameengine CXX)

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(LIB "./lib")

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${LIB}/lua-5.3.5)
add_subdirectory(${LIB}/SFML-2.5.1)

if(MSVC)
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /MD")
    # /MD (or /MDd for debug) 

    add_compile_options(/MP)				#Use multiple processors when building
	add_compile_options(/W4 /wd4201 /WX)	#Warning level 4, all warnings are errors
else()
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
    add_compile_options(-W -Wall -Werror) #All Warnings, all warnings are errors
endif()

include_directories(src/
                    ${LIB}/lua-5.3.5/src
                    ${LIB}/sol2/include
                    ${LIB}/SFML-2.5.1/include)

file(GLOB VENDORS_SOURCES
                ${LIB}/sol2/include/sol.hpp)

file(GLOB PROJECT_HEADERS
                        src/*.h)
file(GLOB PROJECT_SOURCES
                        src/*.cpp)

add_executable(${PROJECT_NAME} 
                ${VENDORS_SOURCES}
                ${PROJECT_SOURCES}
                ${PROJECT_HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME}
                        LuaLib
                        sfml-graphics
                        sfml-window
                        sfml-audio
                        sfml-system)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:LuaLib>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:sfml-graphics>
        $<TARGET_FILE:sfml-window>
        $<TARGET_FILE:sfml-system>
        $<TARGET_FILE:sfml-audio>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)
