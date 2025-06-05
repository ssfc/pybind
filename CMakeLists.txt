cmake_minimum_required(VERSION 3.28)
project(pybind)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_PREFIX_PATH "C:/vcpkg/installed/x64-windows")

# 查找 pybind11 包
find_package(pybind11 CONFIG REQUIRED)

add_executable(pybind main.cpp)

# 链接 pybind11 到你的 target
target_link_libraries(pybind PRIVATE pybind11::pybind11)