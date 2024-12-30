cmake_minimum_required(VERSION 3.22)  # 确保使用支持 C++ 模块的版本  
project(StatisticsCpp LANGUAGES CXX)  

# 设置 C++ 标准为 C++20 或 C++23  
set(CMAKE_CXX_STANDARD 23)  # 或者 23  
set(CMAKE_CXX_STANDARD_REQUIRED ON)  

# 启用实验性 C++ 模块支持  
set(CMAKE_EXPERIMENTAL_CXX_MODULES ON)  
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)   

# 添加包含目录  
include_directories(include)  

# 添加模块库  
add_library(statistics SHARED)  # 创建模块库  
target_sources(statistics  
    PRIVATE  
        src/statistics/statistics.cpp  
    PUBLIC  
        FILE_SET cxx_modules TYPE CXX_MODULES FILES src/statistics/statistics.ixx  
) 



# 添加可执行文件  
add_executable(app src/app/main.cpp)  
target_link_libraries(app PRIVATE statistics)  # 链接模块库

target_include_directories(statistics PUBLIC src/statistics) 
target_include_directories(app PUBLIC src/statistics) 