cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(texteditor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug
        CACHE STRING
            "Choose the type of build (Debug or Release)"
            FORCE
    )
endif()

# configure_file(config.h.in config.h)

find_package(SFML 2.5 
    COMPONENTS 
    system window graphics network audio REQUIRED)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR})
set(SOURCES 
    ${SOURCE_DIR}/src/main.cpp
    ${SOURCE_DIR}/src/document.cpp
    ${SOURCE_DIR}/src/RenderEditor.cpp
    ${SOURCE_DIR}/src/Content.cpp
    ${SOURCE_DIR}/src/input.cpp)

# I don't believe we need to define HEADERS
# set(HEADERS ${SOURCE_DIR}/include/*.h)

add_executable(texteditor ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_BINARY_DIR}")

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)