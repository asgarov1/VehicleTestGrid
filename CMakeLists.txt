cmake_minimum_required(VERSION 3.16)
project(griddisplay)

set(CMAKE_CXX_STANDARD 20)

add_executable(gridserver server/main.cpp server/RaceField.cpp server/RaceField.h server/StringUtil.cpp
        server/StringUtil.h server/server.h)
add_executable(vehicleclient client/main.cpp)
add_executable(griddisplay display/display_main.cpp display/display_main.h)
