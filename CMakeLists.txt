cmake_minimum_required(VERSION 3.20)

project(HTI VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wextra")

add_executable(hti main.cc)
