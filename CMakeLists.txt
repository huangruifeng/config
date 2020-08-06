cmake_minimum_required(VERSION 3.8.2)

project(config)

set(CMAKE_OBJECT_PATH_MAX 512)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

if(WIN32)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi /MP")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MP")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE  "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_DIRECTORY ${PROJECT_SOURCE_DIR}/src)

list(APPEND source
     ${SOURCE_DIRECTORY}/config.h
     ${SOURCE_DIRECTORY}/config.cpp
    )
add_library(config ${source})

if(ENABLE_TEST)
add_executable(Test test/main.cxx)
target_link_libraries(Test config)
endif()