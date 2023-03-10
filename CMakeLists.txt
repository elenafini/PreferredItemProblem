#CMake is not mandatory for your solution, this is provided simply for convenience
#You are welcome to return an xcode project or visual studio project file instead
cmake_minimum_required(VERSION 3.23)

project(
  PreferredElementCPPCase
  VERSION 1.0
  LANGUAGES CXX)

add_executable(PreferredElementCPPCase
                src/catch2/catch.hpp
                src/main.cpp
                src/preferredItem.h
                src/preferredItem.cpp
                src/testCases.cpp
                src/brick.cpp
                src/item.cpp
                src/masterData.cpp
                src/serviceFunctions.cpp
                #Add any additional files here
)

set_target_properties(PreferredElementCPPCase PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
)

include_directories(src)