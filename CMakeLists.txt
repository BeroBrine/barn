cmake_minimum_required(VERSION 3.27.4)

project(barn VERSION 1.0.0 DESCRIPTION "barn - Game Engine" LANGUAGES CXX)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/barn/vendor/spdlog/include)
add_compile_options(
    "-Wall" "-Werror"
)

set(CMAKE_BUILD_TYPE "Debug")

add_library(mylib SHARED src/barn/app.cpp
                        src/barn/Log.cpp)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/barn/vendor/spdlog/include/spdlog)

add_executable(barn ${CMAKE_CURRENT_SOURCE_DIR}/sandbox/src/application.cpp)
target_link_libraries(barn PUBLIC mylib)


