/***************************************************************************
 * VGS Proxy C99 style integration - with OpenSSL and libcurl
 * 2018 gjyoung1974
 */

#include <stdio.h>
#include "openssl-post-vgs.h" //declare our OpenSSL demo client
#include "libcurl-post-vgs.h" //declare our libcurl demo client

int main() {
    printf("\n");
    printf("*********************************************\n");
    printf("proxying to our endpoint via VGS with OpenSSL\n");
    printf("*********************************************\n");
    printf("\n");
    //post_with_openssl(); //demo VGS integration via OpenSSL
    printf("\n");
    printf("proxying to our endpoint via VGS with libcurl\n");
    //post_with_libcurl(); //demo VGS integration via libcurl
    return 0;
}
