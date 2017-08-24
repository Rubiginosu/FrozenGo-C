//
// Created by axoford12 on 8/24/17.
//

#ifndef FROZENGO_C_MD5_SUM_H
#define FROZENGO_C_MD5_SUM_H
#include <openssl/md5.h>
#include <memory.h>
#include <stdio.h>

/**
 * 本函数调用OpenSSL库进行Md5计算,并将计算的值返回到调用者处.
 * @param src
 * 要进行校验和计算的数
 * @return
 * 返回最终校验和(%x)
 * 请用free释放该指针!
 */
char* md5_sum_get(char* src);
#endif //FROZENGO_C_MD5_SUM_H
