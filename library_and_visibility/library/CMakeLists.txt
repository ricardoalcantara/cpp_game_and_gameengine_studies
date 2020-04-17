cmake_minimum_required(VERSION 3.0.0)
project(library VERSION 0.1.0)

add_compile_definitions(COMPILING_DLL)

include_directories(include/)

add_library(${PROJECT_NAME} SHARED src/Library.cpp src/Library.h src/Logger.cpp src/Logger.h src/Core.h src/Application.cpp src/Application.h library.h src/EntryPoint.h)
