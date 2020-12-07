cmake_minimum_required (VERSION 2.8)

project(main)

include_directories(/usr/local/bob/lua-cmake/)

link_directories("/usr/local/bob/lua/lua-cmake/")

link_libraries(lua)


add_executable(main main.cpp)
