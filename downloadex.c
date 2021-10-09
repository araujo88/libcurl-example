// Networking example in C using libcurl library
#include "C:\curl-7.79.1-win64-mingw\include\curl\curl.h" // windows
//#include <curl/curl.h> // unix
#include <stdio.h>
#include <stdlib.h>

size_t got_data(char *buffer, size_t itemsize, size_t nitems, void *ignorethis) {
    size_t bytes = itemsize * nitems;
    int linenumber = 1;
    printf("New chunk (%u bytes)\n", bytes);
    printf("%d:\t", linenumber);
    for (int i = 0; i < bytes; i++) {
        printf("%c", buffer[i]);
        if (buffer[i] == '\n') {
            linenumber++;
            printf("%d:\t", linenumber);
        }
    }
    printf("\n\n");
    return bytes;
}

int main(void) {
    CURL *curl = curl_easy_init(); // initialize Curl pointer

    if (!curl) {
        fprintf(stderr, "ERROR - failed to initialize Curl\n"); // check for errors in initialization
        return EXIT_FAILURE;
    }

    // set options

    curl_easy_setopt(curl, CURLOPT_URL, "http://www.brainjar.com/java/host/test.html"); // sets url
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data); // sets function to print data

    // perform action

    CURLcode result = curl_easy_perform(curl);

    if (result != CURLE_OK) {
        fprintf(stderr, "ERROR - failed to download: %s\n", curl_easy_strerror(result));
    }

    curl_easy_cleanup(curl);
    return EXIT_SUCCESS;
}