# © 2021 Joseph Cameron - All Rights Reserved

cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

project(null)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/jfc-cmake/jfclib.cmake")

option(JFC_BUILD_DEMO "Build the demo" ON)
option(JFC_BUILD_DOCS "Build documentation" OFF)
option(JFC_BUILD_TESTS "Build unit tests" ON)

jfc_project(library
    NAME "jfcapplicationpaths"
    VERSION 1.0
    DESCRIPTION "app paths"
    C++_STANDARD 17
    C_STANDARD 90
    TYPE STATIC

    PUBLIC_INCLUDE_DIRECTORIES
        ${CMAKE_CURRENT_SOURCE_DIR}/include

    SOURCE_LIST
        ${CMAKE_CURRENT_SOURCE_DIR}/src/stub.cpp
)

if (NOT ${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    target_link_libraries(${PROJECT_NAME} stdc++fs)
endif()

if (JFC_BUILD_DEMO)
    add_subdirectory(demo)
endif()

if (JFC_BUILD_TESTS)
    add_subdirectory(test)
endif()

if (JFC_BUILD_DOCS)
    add_subdirectory(docs)
endif()

