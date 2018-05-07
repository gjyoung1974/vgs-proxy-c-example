cmake_minimum_required(VERSION 3.8)
project(vgs_proxy_c_example C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L /usr/lib/x86_64-linux-gnu -lcrypto -lssl -lcurl")

set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")

include(cmake/DownloadProject.cmake)

download_project(
    PROJ   googletest
    GIT_REPOSITORY      git@github.com:google/googletest.git
    GIT_TAG             master
    ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

add_executable(vgs_proxy_c_example main.c openssl-post-vgs.c openssl-post-vgs.h libcurl-post-vgs.c libcurl-post-vgs.h)
include_directories(/usr/include/x86_64-linux-gnu)
