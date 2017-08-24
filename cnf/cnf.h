//
// Created by axoford12 on 8/23/17.
//

#include <stdio.h>

#ifndef FROZENGO_C_CNF_H
#define FROZENGO_C_CNF_H
typedef struct{
    unsigned long port;
    char* key;
} config;

typedef enum{
    PARSE_OK = 0,
    ERR_MAX_LENGTH_TOO_SHORT,
    ERR_CONFIG_FILE_NOT_FOUND
}config_init_error;
/**
 * 初始化conf，从../fg.ini中读取文件。
 * @return
 * 错误
 */
config_init_error config_init(config *);
#endif //FROZENGO_C_CNF_H
