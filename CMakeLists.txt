cmake_minimum_required(VERSION 3.8.0)

cmake_minimum_required(VERSION 3.10)
project(cpp_template)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)

# 设置头文件路径
include_directories(include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# 查找源文件
file(GLOB SOURCES src/*.cpp)

# 生成可执行文件
add_executable(exec ${SOURCES})
