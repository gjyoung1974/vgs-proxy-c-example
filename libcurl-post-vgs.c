/*
 * 2018 gjyoung1974@gmail.com
 *
 * VGS C libcurl  example
 *
 * This example demonstrates sharing sensitive data with a 3rd party processor API
 * 1. Collect a Payment Account Number token value from our Backend database
 * 2. Securely share it with an upstream 3rd party processor's API
 * 3. Notice that we have not had to handle the sensitive
 *
 *      The handling of sensitive data is covered by the VGS proxy on behalf by simply setting up a forward proxy
 *      VGS Proxy details are in libcurl by:
 *      CURLOPT_PROXY <your vault's proxy URL>
 *      CURLOPT_PROXYUSERNAME <your vault's proxy username>
 *      CURLOPT_PROXYPASSWORD <your vault's proxy password>
 */

#include "libcurl-post-vgs.h"
#include <stdio.h>
#include <curl/curl.h>

void post_with_libcurl(void)
{
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;

    headers = curl_slist_append(headers, "Shoesize: 11"); // Add any required headers
    headers = curl_slist_append(headers, "Content-type: application/json"); //set the mime=type as JSON

    curl_global_init(CURL_GLOBAL_ALL);

    /* get a curl handle */
    curl = curl_easy_init();
    if(curl) {
        /* First set the URL that is about to receive our POST. This URL can
           just as well be a https:// URL if that is what should receive the
           data. */
        curl_easy_setopt(curl, CURLOPT_URL, "https://httpbin.org/post"); //Third Party API to share sensitive data with

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0); //TODO: fix this never blindly accept server certificates
        curl_easy_setopt(curl, CURLOPT_PROXY, "http://tntlvnzzqsz.SANDBOX.verygoodproxy.com:8080");
        curl_easy_setopt(curl, CURLOPT_PROXYUSERNAME, "US2dihmmMZD8BGsQj2yKgjZk");
        curl_easy_setopt(curl, CURLOPT_PROXYPASSWORD, "6e478e95-52ed-4c3b-9493-3aefa7f9137a");

        /* Now specify the POST data */
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 27);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"CCN\": \"4012882363931881\"}");  //The encrypted test Visa PAN from our backend database
                                                                                        //ClearText is: 4012888888881881
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

}