cmake_minimum_required(VERSION 3.24...3.30)
project(enigmapp VERSION 0.1
                 DESCRIPTION "Enigma Machine in C++"
                 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

find_package(CLI11 REQUIRED)

add_subdirectory(src)
add_executable(enigmapp enigmapp.cpp)
target_link_libraries(enigmapp CLI11::CLI11)
target_link_libraries(enigmapp enigma)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
