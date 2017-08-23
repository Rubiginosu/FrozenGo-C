//
// Created by axoford12 on 8/23/17.
//

#include<stdlib.h>
#include <memory.h>
#include "cnf.h"

#define LINE_LENGTH 1024
#define ATTR_MAX_LENGTH 20
enum errors {
    ERR_MAX_LENGTH_TOO_SHORT = 0,
    ERR_CONFIG_FILE_NOT_FOUND
};

/**
 * 本函数用于过滤一个字符串中的所有字符
 * @param filter_char
 * 要过滤的字符串
 * @param filter
 * 要过滤的字符，比如' '
 */
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

void handle(char *attr_name, char *attr_value,config *attr_dst) {
    if(!strcmp(attr_name,"port")){
        attr_dst->port = (int)strtol(attr_value,NULL,10);
    }
}

/**
 * 解析一个无Section的ini文件。并且不含include
 * @param f
 * @param attr_dst
 * @return 错误
 */
int parse(FILE *f, config *attr_dst) {
    char *buf;
    buf = malloc(sizeof(char) * LINE_LENGTH);
    while (fgets(buf, LINE_LENGTH, f)) {
        char attr_name[ATTR_MAX_LENGTH] = ""; // 读出的属性名称
        char attr_value[ATTR_MAX_LENGTH] = ""; // 读出的属性值
        int equal_index = 0;
        if (buf[0] == '#')
            continue;

        filter_char(buf, ' ');
        for (equal_index = 0; buf[equal_index] != '='; ++equal_index) {
            if (equal_index <= ATTR_MAX_LENGTH) ERR_MAX_LENGTH_TOO_SHORT;
            attr_name[equal_index] = buf[equal_index];
        }
        attr_name[++equal_index] = '\0';
        for (int counter = equal_index; buf[counter] != '\0'; ++counter) { // Counter的存在是为了修正偏移
            if (counter <= ATTR_MAX_LENGTH) ERR_MAX_LENGTH_TOO_SHORT;
            attr_value[counter - equal_index] = buf[counter];
        }
        attr_value[equal_index + 1] = '\0'; // 显式加上结束符
        handle(attr_name,attr_value,attr_dst);
    }
    return 0;
}

int config_init(config *config) {
    FILE* config_file = fopen("../fgo.ini","r");
    if(config_file == NULL){
        return ERR_CONFIG_FILE_NOT_FOUND;
    }
    return parse(config_file,config);
}

