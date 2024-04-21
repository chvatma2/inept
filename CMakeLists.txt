cmake_minimum_required(VERSION 3.21)

project(
  Inept
  VERSION 0.1.0
  DESCRIPTION "Inconsequential new experimental path tracer"
  LANGUAGES CXX)
include(CTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS NO)

add_subdirectory(core)
add_subdirectory(inept-cli)
