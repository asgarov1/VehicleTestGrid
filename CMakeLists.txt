cmake_minimum_required(VERSION 3.16)
project(VehicleTestGrid)

set(CMAKE_CXX_STANDARD 17)

add_executable(gridserver server/main.cpp server/RaceField.cpp server/RaceField.h server/StringUtil.cpp
        server/StringUtil.h server/Server.cpp server/Server.h)
add_executable(vehicleclient client/main.cpp)
add_executable(griddisplay display/display_main.cpp display/display_main.h)
