//
// Created by axoford12 on 8/24/17.
//

#include "str_filter.h"



void filter_char(char *filter_char, char filter) {
    int rel_index = 0;
    int no_filter = 0;
    for (int i = 0; filter_char[i] != '\0'; ++i) {

        if (filter_char[i] != filter) {
            no_filter++;
            filter_char[rel_index] = filter_char[i];
            rel_index++;
        }

    }
    filter_char[no_filter] = '\0';
}
