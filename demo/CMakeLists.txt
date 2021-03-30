# © 2021 Joseph Cameron - All Rights Reserved

cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

jfc_project(executable
    NAME "jfcapplicationpaths-demo"
    VERSION 1.0
    DESCRIPTION "jfc-application_paths demonstration"
    C++_STANDARD 17
    C_STANDARD 90

    SOURCE_LIST
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp

    PRIVATE_INCLUDE_DIRECTORIES
        "${jfcapplicationpaths_INCLUDE_DIRECTORIES}"

    LIBRARIES
        "${jfcapplicationpaths_LIBRARIES}"

    DEPENDENCIES
        "jfcapplicationpaths"
)

