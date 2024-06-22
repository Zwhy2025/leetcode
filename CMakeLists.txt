cmake_minimum_required(VERSION 3.10)
project(DesignPatterns)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_VERBOSE_MAKEFILE 1)  # 开启调试信息

# 查找GTest库
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
#MESSAGE(${GTEST_INCLUDE_DIRS})
MESSAGE(STATUS ${GTEST_BOTH_LIBRARIES})
MESSAGE(${GTEST_LIBRARIES})
MESSAGE(${GTEST_MAIN_LIBRARIES})


if(GTest_FOUND)
    message(STATUS "GTest found")
else()
    message(FATAL_ERROR "GTest not found")
endif()
include_directories(${GoogleTest_INCLUDE_DIRS})
link_directories(${GoogleTest_LIBRARY_DIRS})
message(STATUS "GTest_LIBRARIES: ${GoogleTest_LIBRARY_DIRS}")
message(STATUS "GTest_INCLUDE_DIRS: ${GoogleTest_INCLUDE_DIRS}")

find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
    message(STATUS "OpenCV found")
else()
    message(FATAL_ERROR "OpenCV not found")
endif()
message(STATUS "OpenCV_LIBRARIES: ${OpenCV_LIBRARIES}")
message(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")


#include_directories(/usr/local/include/gtest)
#link_directories(/usr/local/lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# 设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# 为行为型设计模式添加库
aux_source_directory(. Leetcode_SRC_FILES)
add_library(leetcode STATIC ${Leetcode_SRC_FILES})

# 设置库的包含目录
target_include_directories(leetcode PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 创建可执行文件 display
add_executable(display display.cpp)
target_link_libraries(display leetcode)

# 创建可执行文件 test
add_executable(test test.cc)
target_link_libraries(test leetcode ${GTEST_BOTH_LIBRARIES})
target_include_directories(test PRIVATE ${GTest_INCLUDE_DIRS})
# 打印调试路径

# 如果需要，链接pthread
if(UNIX)
    target_link_libraries(test pthread )
endif()

