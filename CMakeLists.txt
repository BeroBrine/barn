cmake_minimum_required(VERSION 3.27.4)

project(barn)


add_library(mylib SHARED src/barn/app.cpp)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


add_executable(barn ${CMAKE_CURRENT_SOURCE_DIR}/sandbox/src/application.cpp)
target_link_libraries(barn PUBLIC mylib)


