cmake_minimum_required(VERSION 3.17)
project(SortViz)

set(CMAKE_CXX_STANDARD 20)

add_executable(SortViz main.cpp Sort.cpp Sort.h Number.cpp Number.h)

set(SFML_ROOT "C:/SFML-2.5.1")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED COMPONENTS graphics window network audio system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SortViz ${SFML_LIBRARIES})
endif()