# CMake version string
cmake_minimum_required(VERSION 3.2.1)

# Project
project(example LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../build)

# Add Qt Creator import path
set(QML_IMPORT_PATH "${QML_IMPORT_DIRS}" CACHE STRING "Qt Creator extra qml import paths")

# Find Qt libraries
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick Svg QuickControls2 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Svg QuickControls2 REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        example_qml.qrc
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME}  PUBLIC "../includes" )
target_link_directories(${PROJECT_NAME}  PUBLIC "../build")
target_link_libraries(${PROJECT_NAME}
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick industrial_controls)

