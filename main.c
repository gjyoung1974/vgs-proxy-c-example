/***************************************************************************
 * VGS Proxy C99 style integration - with OpenSSL and libcurl
 * 2018 gjyoung1974
 */

#include <stdio.h>
#include "openssl-post-demo.h" //declare our OpenSSL demo client
#include "libcurl-post-demo.h" //declare our libcurl demo client

int main() {
    post_with_openssl(); //demo VGS integration via OpenSSL
    //post_with_libcurl(); //demo VGS integration via libcurl
    return 0;
}