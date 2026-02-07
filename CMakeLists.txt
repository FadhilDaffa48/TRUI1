cmake_minimum_required(VERSION 3.16)
project(converter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(converter
  src/main.cpp
  src/CsvHandler.cpp
  src/TsvHandler.cpp
  src/Length.cpp
  src/TimeConverter.cpp
)

target_include_directories(converter PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)
