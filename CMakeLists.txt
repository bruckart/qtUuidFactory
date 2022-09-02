
cmake_minimum_required(VERSION 3.20.4)

project(qtUuidFactory VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/Users/robertbruckart/Qt/6.3.0/macos/")

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOUIC ON)

# Instruct Cmake to run automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(_INCLUDE_DIRS
    # Qt5
    ${Qt5Widgets_INCLUDES}
    # local
    ${CMAKE_CURRENT_LIST_DIR}/include)

include_directories(${_INCLUDE_DIRS}
                    ${PROJECT_BINARY_DIR}
)

set(_UI
    ${CMAKE_CURRENT_LIST_DIR}/src/MyUuidWidget.ui
)

set(_HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/include/MyUuidWidget.h
)

set(_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/MyUuidWidget.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
)

qt6_wrap_cpp(qtHelloWorld_header_moc ${_HEADERS})
qt6_wrap_ui(qtHelloWorld_ui_moc ${_UI})

add_executable(qtUuidFactory
    ${qtHelloWorld_header_moc}
    ${qtHelloWorld_ui_moc}
    ${_SOURCES}
)

target_link_libraries(qtUuidFactory
    Qt6::Widgets
)
