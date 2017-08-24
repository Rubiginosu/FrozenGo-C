//
// Created by axoford12 on 8/24/17.
//

#ifndef FROZENGO_C_MD5_CMP_H
#define FROZENGO_C_MD5_CMP_H

#include <stdbool.h>

/**
 * 本函数用于比较两个字符串的md5校验和
 *  strcmp进行比较.
 * @param src
 * @param dst
 * @return
 * bool类型,是否校验成功.
 */
bool str_md5_cmp(char *src, char *dst);

#endif //FROZENGO_C_MD5_CMP_H
