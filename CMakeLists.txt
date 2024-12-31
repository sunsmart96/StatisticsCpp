cmake_minimum_required(VERSION 3.22)  # 确保使用支持 C++ 模块的版本  
project(StatisticsCpp LANGUAGES CXX)  

# 设置 C++ 标准为 C++20 或 C++23  
set(CMAKE_CXX_STANDARD 23)  # 或者 23
set(CMAKE_C_STANDARD 11)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)  
set(CMAKE_EXPERIMENTAL_CXX_MODULES ON)  
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)   

set(BUILD_SHARED_LIBS ON)  
# 添加包含目录  
include_directories(include)

set(CMAKE_VERBOSE_MAKEFILE ON) 

# 使用 FetchContent 下载 fmt 库  
include(FetchContent)  

FetchContent_Declare(  
    fmt  
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git  
    GIT_TAG 11.1.1  # 或者指定具体的标签  
)  

# 下载并构建 fmt 库  
FetchContent_MakeAvailable(fmt)

# 使用 FetchContent 下载 fmt 库  
include(FetchContent)  

FetchContent_Declare(  
    xlnt  
    GIT_REPOSITORY https://github.com/tfussell/xlnt.git
    GIT_TAG master  # 或者指定具体的标签  
)  
# 下载并构建 fmt 库  
FetchContent_MakeAvailable(xlnt)

# 添加模块库  
add_library(statistics SHARED)  # 创建模块库  
target_sources(statistics  
    PRIVATE  
        src/statistics/statistics.cpp  
    PUBLIC  
        FILE_SET cxx_modules TYPE CXX_MODULES FILES src/statistics/statistics.ixx  
) 

target_link_libraries(statistics PRIVATE fmt xlnt)  

# 添加可执行文件  
add_executable(app src/app/main.cpp)  
target_link_libraries(app PRIVATE statistics fmt xlnt)  # 链接模块库

target_include_directories(statistics PUBLIC src/statistics) 
target_include_directories(app PUBLIC src/statistics) 

add_custom_command(TARGET app POST_BUILD  
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:fmt::fmt> $<TARGET_FILE_DIR:app>) 
add_custom_command(TARGET app POST_BUILD  
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:xlnt> $<TARGET_FILE_DIR:app>)  