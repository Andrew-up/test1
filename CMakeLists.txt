cmake_minimum_required(VERSION 3.5)

project(untitled1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Protobuf_USE_STATIC_LIBS ON )

include(${PROTOBUF_ROOT}lib/cmake/protobuf/protobuf-config.cmake)
include(${PROTOBUF_ROOT}lib/cmake/protobuf/protobuf-module.cmake)
include(${PROTOBUF_ROOT}lib/cmake/protobuf/protobuf-options.cmake)
include(${PROTOBUF_ROOT}lib/cmake/protobuf/protobuf-targets.cmake)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
find_package(Protobuf REQUIRED HINTS ${PROTOBUF_ROOT}lib/cmake/protobuf/)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS foo.proto)
ADD_LIBRARY(proto ${PROTO_HDRS} ${PROTO_SRCS})


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        foo.proto
        main.h
        service/TreeGenerator.cpp
        service/TreeGenerator.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(untitled1
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES} ${PROTO_SRCS} ${PROTO_HDRS}
    )
# Define target properties for Android with Qt 6 as:
    set_property(TARGET untitled1 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(untitled1 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(untitled1
            ${PROJECT_SOURCES} ${PROTO_SRCS} ${PROTO_HDRS}
        )
    endif()
endif()


target_link_libraries(untitled1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${Protobuf_LIBRARIES})

set_target_properties(untitled1 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS untitled1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(untitled1)
endif()
