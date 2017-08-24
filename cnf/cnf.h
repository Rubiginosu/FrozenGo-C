//
// Created by axoford12 on 8/23/17.
//

#include <stdio.h>

#ifndef FROZENGO_C_CNF_H
#define FROZENGO_C_CNF_H
typedef struct{
    int port;
} config;

typedef enum{
    OK = 0,
    ERR_MAX_LENGTH_TOO_SHORT,
    ERR_CONFIG_FILE_NOT_FOUND
}errors;
/**
 * 初始化conf，从../fg.ini中读取文件。
 * @return
 * 错误
 */
errors config_init(config *);
#endif //FROZENGO_C_CNF_H
