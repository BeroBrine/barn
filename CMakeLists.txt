cmake_minimum_required(VERSION 3.27.4)

project(barn)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/barn/vendor/spdlog/include)

add_library(mylib SHARED src/barn/app.cpp
                        src/barn/Log.cpp)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/barn/vendor/spdlog/include/spdlog)

add_executable(barn ${CMAKE_CURRENT_SOURCE_DIR}/sandbox/src/application.cpp)
target_link_libraries(barn PUBLIC mylib)


