cmake_minimum_required(VERSION 3.10)
project(vgs_proxy_c_example C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L /usr/lib/x86_64-linux-gnu -lcrypto -lssl -lcurl")

add_executable(vgs_proxy_c_example main.c openssl-post-demo.c openssl-post-demo.h libcurl-post-demo.c libcurl-post-demo.h)
include_directories(/usr/include/x86_64-linux-gnu)