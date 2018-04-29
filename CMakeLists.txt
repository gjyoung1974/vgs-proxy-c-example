cmake_minimum_required(VERSION 3.10)
project(vgs_proxy_c_example C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L /usr/lib/x86_64-linux-gnu/openssl-1.0.2 -lcrypto -lssl")

add_executable(vgs_proxy_c_example main.c)
include_directories(/usr/include/x86_64-linux-gnu/openssl)