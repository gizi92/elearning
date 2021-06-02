#ifndef _PROGBAR_H
#define _PROGBAR_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <curl/curl.h>

typedef struct {
    long total_bytes;
    long total_expected;
    double exp_bytes_per_url;
    long current_bytes;
    long url_so_far;
    long total_urls;
} status_info;

void update_bar(int percent_done, status_info *sinfo);
size_t got_data(char *buffer, size_t itemsize, size_t numitems, void *stinfo);
bool download_url(char *url, status_info *sinfo);

#endif