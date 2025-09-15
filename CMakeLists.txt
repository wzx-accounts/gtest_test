cmake_minimum_required(VERSION 3.0)
project(gtest_project)

set(CMAKE_CXX_STANDARD 11)

# 声明依赖, 1.12.1是最后一个支持C++11的版本
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/third/googletest
)

set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# 指定C/C++ #include时搜索的路径
include_directories(include)
include_directories(third/googletest/googletest/include)
include_directories(third/googletest/googlemock/include)

# 查找所有测试文件
file(GLOB_RECURSE GTEST_SRC_FILES ${CMAKE_SOURCE_DIR}/test/*.cpp)
message(STATUS "GTEST_SRC_FILES: ${GTEST_SRC_FILES}")

# 将所有文件合并成SRC_FILES变量
LIST(APPEND SRC_FILES ${GTEST_SRC_FILES})
message(STATUS "SRC_FILES ${SRC_FILES}")

# 生成二进制，并声明二进制的依赖
add_executable(gtest_project ${SRC_FILES})

# 链接gtest/gmock的库
target_link_libraries(gtest_project gtest gmock)

# 链接自己测试代码的库
target_link_libraries(gtest_project twosum)

add_subdirectory(src)
