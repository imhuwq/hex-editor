cmake_minimum_required(VERSION 3.8)

project(hex-editor)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)

# things to be gathered ----------
set(PRJ_INCLUDES "")                # include directories
set(PRJ_LIBRARIES "")               # libraries
set(PRJ_LIBRARIES_DEBUG "")         # libraries only needed for debug purpose
set(PRJ_SOURCES "")                 # source files
# things to be gathered ----------


# for debug ----------
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")
find_package(Gperftools REQUIRED)
list(APPEND PRJ_INCLUDES ${GPERFTOOLS_INCLUDE_DIR})
list(APPEND PRJ_LIBRARIES_DEBUG ${GPERFTOOLS_LIBRARIES})
# ---------- for debug


# setup qt5 ----------
# notice for developer: Qt5 must be installed in home directory
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(Qt5Dir "$ENV{HOME}/Qt/5.10.0")
file(GLOB Qt5Modules "${Qt5Dir}/gcc_64/lib/cmake/*")
foreach (Qt5Module ${Qt5Modules})
    if (IS_DIRECTORY ${Qt5Module})
        get_filename_component(ModuleName ${Qt5Module} NAME_WE)
        set("${ModuleName}_DIR" ${Qt5Module})
    endif ()
endforeach ()
# ---------- setup qt5


# the packages required ----------
find_package(Qt5Core)
find_package(Qt5Widgets)
# ---------- the packages required


# set the include dirs ----------
list(APPEND PRJ_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include")
list(APPEND PRJ_INCLUDES ${Qt5Core_INCLUDE_DIRS})
list(APPEND PRJ_INCLUDES ${Qt5Widgets_INCLUDE_DIRS})
list(REMOVE_DUPLICATES PRJ_INCLUDES)
include_directories(${PRJ_INCLUDES})
# ---------- set the include dirs


# set the libs ----------
list(APPEND PRJ_LIBRARIES ${Qt5Core_LIBRARIES})
list(APPEND PRJ_LIBRARIES ${Qt5Widgets_LIBRARIES})
# ---------- set the libs


# set the sources ----------
file(GLOB_RECURSE Sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE QObjects "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
list(APPEND PRJ_SOURCES ${QObjects})
list(APPEND PRJ_SOURCES ${Sources})
message(STATUS ${PRJ_SOURCES})
# ---------- set the sources


# build the main ----------
add_executable(hex_editor hex_editor.cpp ${PRJ_SOURCES})
target_link_libraries(hex_editor ${PRJ_LIBRARIES})
target_link_libraries(hex_editor debug ${PRJ_LIBRARIES_DEBUG})
# ---------- build the main
