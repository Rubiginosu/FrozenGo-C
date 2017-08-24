//
// Created by axoford12 on 8/24/17.
//

#include "md5_cmp.h"
#include "md5_sum.h"

bool str_md5_cmp(char *src, char *dst) {
    char *src_sum = md5_sum_get(src);
    char *dst_sum = md5_sum_get(dst);
    return strcmp(src_sum,dst_sum) == 0;
}
