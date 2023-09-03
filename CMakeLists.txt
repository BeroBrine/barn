cmake_minimum_required(VERSION 3.27.4)

project(barn VERSION 1.0.0 DESCRIPTION "barn - Game Engine" LANGUAGES CXX)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/barn/vendor/spdlog/include)
add_compile_options(
    "-Wall" "-Werror" "-g"
)

set(CMAKE_BUILD_TYPE "Debug")


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/barn/vendor/glfw)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/barn/vendor/spdlog)

add_library(mylib SHARED src/barn/app.cpp
src/barn/Log.cpp
src/platform/linuxWindow.cpp
)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/sandbox/src/application.cpp)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(mylib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/barn)
target_include_directories(mylib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}src/barn/vendor/spdlog/include)
target_include_directories(mylib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/barn/vendor/glfw/include)
target_include_directories(mylib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/platform)

target_link_libraries(barn PRIVATE mylib glfw)
target_link_directories(barn PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/build/src/barn/vendor/glfw/src)





