//
// Created by axoford12 on 8/23/17.
//

#include <stdio.h>

#ifndef FROZENGO_C_CNF_H
#define FROZENGO_C_CNF_H
typedef struct{
    int port;
} config;
int parse(FILE *f,config* attr_src);
#endif //FROZENGO_C_CNF_H
