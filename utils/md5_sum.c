//
// Created by axoford12 on 8/24/17.
//

#include <stdlib.h>
#include "md5_sum.h"

char *md5_sum_get(char *src) {
    char res[16][3];
    char* result = malloc(sizeof(char) * 32);
    unsigned char out_buf[16];
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx,src,strlen(src));
    MD5_Final(out_buf,&ctx);
    for (int i = 0; i < 16; ++i) {
        sprintf(res[i],"%02x",out_buf[i]);
    }
    for (int j = 0; j < 16; ++j) {
        strcat(result,res[j]);
    }
    return result;
}
