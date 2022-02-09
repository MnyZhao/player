
cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.
set(CMAKE_VERBOSE_MAKEFILE on)
project("player")



add_library( # Sets the name of the library.
        player

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        cpp/native-lib.cpp)

# 引入当前头文件
include_directories(${CMAKE_SOURCE_DIR}/cpp/include)
#打印当前 cmakeLists 的路径
message("当前cmakel路径: ${CMAKE_SOURCE_DIR} \n cpu架构：${CMAKE_ANDROID_ARCH_ABI}")
#设置C++ 编译 -L 设置库路径 -L设置的路径与下面的link_directories 应该类似
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/jniLibs/${CMAKE_ANDROID_ARCH_ABI}")
#指定静态库或动态库的搜索路径 该指令的作用主要是指定要链接的库文件的路径
# 自己写的动态库文件放在自己新建的目录下时，可以用该指令指定该目录的路径以便工程能够找到。
link_directories(
        ${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}
)
find_library(
        log-lib
        log)
#将指定的静态库连接到可执行文件上
target_link_libraries(
        player

        avformat avcodec avfilter avutil swresample swscale

        ${log-lib})