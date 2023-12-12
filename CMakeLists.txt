cmake_minimum_required(VERSION 3.18)

project(assessment
    VERSION 1.0
    DESCRIPTION "Evaluation assessment for CMPSC 200: Computer Organization, Allegheny College"
    LANGUAGES C CXX ASM
)

OPTION(EVALUGATOR "Evaluate assessment using cmocka unit tests" OFF)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if(EVALUGATOR)
    enable_language(C CXX ASM)
    add_subdirectory(./source)
    add_subdirectory(./evalugator)
endif(EVALUGATOR)

if(NOT EVALUGATOR)
    include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
    set(PICO_BOARD pico_w)
    pico_sdk_init()
    enable_language(C CXX ASM)
    add_subdirectory(./source)
endif(NOT EVALUGATOR)

