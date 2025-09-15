cmake_minimum_required(VERSION 3.0)
project(gtest_project)

set(CMAKE_CXX_STANDARD 11)

# 准备依赖
set(GTEST_TAR_FILEPATH "${CMAKE_SOURCE_DIR}/third/googletest-release-1.12.1.tar.gz")
set(GTEST_TAR_EXTRACT_DIR "${CMAKE_SOURCE_DIR}/third/googletest")

# 如果解压目录已存在，不再重复解压
if (NOT EXISTS "${GTEST_TAR_EXTRACT_DIR}")
    # 确保目标目录存在
    file(MAKE_DIRECTORY ${GTEST_TAR_EXTRACT_DIR})

    # 执行解压命令
    execute_process(
            COMMAND ${CMAKE_COMMAND} -E tar xzf "${GTEST_TAR_FILEPATH}"
            WORKING_DIRECTORY ${GTEST_TAR_EXTRACT_DIR}                      # 工作目录
            RESULT_VARIABLE result_var                                      # 捕获命令执行结果
            OUTPUT_VARIABLE output_var                                      # 捕获命令的标准输出
            ERROR_VARIABLE error_var                                        # 捕获命令的错误输出
    )

    if (NOT result_var EQUAL 0)
        message(FATAL_ERROR "解压失败：${error_var}")
    else ()
        message(STATUS "解压成功： ${GTEST_TAR_FILEPATH}  --> ${GTEST_TAR_EXTRACT_DIR}")
    endif ()
endif ()

# 指定C/C++ #include时搜索的路径
include_directories(include)
include_directories(third/googletest/googletest-release-1.12.1/googletest/include)
include_directories(third/googletest/googletest-release-1.12.1/googlemock/include)

# 查找所有测试文件
file(GLOB_RECURSE GTEST_SRC_FILES ${CMAKE_SOURCE_DIR}/test/*.cpp)
message(STATUS "GTEST_SRC_FILES: ${GTEST_SRC_FILES}")

# 将所有mod的文件合并成要给SRC_FILES变量
LIST(APPEND SRC_FILES ${GTEST_SRC_FILES})
message(STATUS "SRC_FILES ${SRC_FILES}")

# 生成二进制，并声明二进制的依赖
add_executable(gtest_project ${SRC_FILES})

# 链接gtest/gmock的库
target_link_libraries(gtest_project gtest gmock)

# 链接自己测试代码的库
target_link_libraries(gtest_project twosum)

add_subdirectory(src)

# 设置变量BUILD_SHARED_LIBS，控制googletest生成动态库
set(BUILD_SHARED_LIBS ON)
add_subdirectory(third/googletest/googletest-release-1.12.1)