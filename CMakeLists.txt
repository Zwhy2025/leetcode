cmake_minimum_required(VERSION 3.10)

# 项目信息
project(Leetcode)
# 设置编译标志和C++标准
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_VERBOSE_MAKEFILE ON)

# 常量路径设置
set(PROJECT_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(PROJECT_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 设置包含目录
include_directories(${PROJECT_INCLUDE_DIR})

# 设置输出路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})

# 递归收集 src 及子目录下的 .cpp
file(GLOB_RECURSE LEETCODE_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(leetcode STATIC ${LEETCODE_SRC_FILES})

# 设置目标文件的包含目录
target_include_directories(leetcode PUBLIC ${PROJECT_INCLUDE_DIR})
