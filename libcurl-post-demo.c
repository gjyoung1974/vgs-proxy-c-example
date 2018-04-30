//
// Created by gyoung on 4/30/18.
//

#include "libcurl-post-demo.h"
#include <stdio.h>
#include <curl/curl.h>

void post_with_libcurl(void)
{
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;

    headers = curl_slist_append(headers, "Shoesize: 11");
    headers = curl_slist_append(headers, "Content-type: application/json");

    curl_global_init(CURL_GLOBAL_ALL);

    /* get a curl handle */
    curl = curl_easy_init();
    if(curl) {
        /* First set the URL that is about to receive our POST. This URL can
           just as well be a https:// URL if that is what should receive the
           data. */
        curl_easy_setopt(curl, CURLOPT_URL, "https://tntlvnzzqsz.SANDBOX.verygoodproxy.com/post");
        /* Now specify the POST data */
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 27);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"CCN\": \"4111111111111111\"}");

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