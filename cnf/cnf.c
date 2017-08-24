//
// Created by axoford12 on 8/23/17.
//

#include<stdlib.h>
#include <memory.h>
#include <assert.h>
#include <errno.h>
#include "cnf.h"
#include "../utils/str_filter.h"
#include "../utils/md5_sum.h"

#define LINE_LENGTH 1024
#define ATTR_MAX_LENGTH 40



void handle(char *attr_name, char *attr_value,config *attr_dst) {
    if(!strcmp(attr_name,"port")){
        attr_dst->port = (unsigned)labs(strtol(attr_value,NULL,10));
        assert(attr_dst->port > 0);
    } else if (!strcmp(attr_name,"key")){
        attr_dst->key = md5_sum_get(attr_value);
    }
}

/**
 * 解析一个无Section的ini文件。并且不含include
 * @param f
 * @param attr_dst
 * @return 错误
 */
config_init_error parse(FILE *f, config *attr_dst) {
    char *buf;
    buf = malloc(sizeof(char) * LINE_LENGTH);
    while (fgets(buf, LINE_LENGTH, f)) {
        char attr_name[ATTR_MAX_LENGTH] = ""; // 读出的属性名称
        char attr_value[ATTR_MAX_LENGTH] = ""; // 读出的属性值
        int equal_index = 0;
        if (buf[0] == '#' || buf[0] == '\n')
            continue;

        filter_char(buf, ' ');
        for (equal_index = 0; buf[equal_index] != '='; ++equal_index) {
            if (equal_index > ATTR_MAX_LENGTH)return ERR_MAX_LENGTH_TOO_SHORT;
            attr_name[equal_index] = buf[equal_index];
        }
        attr_name[++equal_index] = '\0';
        int counter;
        for (counter = equal_index; buf[counter] != '\0'; ++counter) { // Counter的存在是为了修正偏移
            if (counter > ATTR_MAX_LENGTH)return ERR_MAX_LENGTH_TOO_SHORT;
            attr_value[counter - equal_index] = buf[counter];
        }
        attr_value[counter - equal_index] = '\0'; // 显式加上结束符
        handle(attr_name,attr_value,attr_dst);
    }
    return PARSE_OK;
}

config_init_error config_init(config *config) {
    errno = 0;
    FILE* config_file = fopen("../fgo.ini","r");
    if(errno){
        printf("%s\n",strerror(errno));
        return ERR_CONFIG_FILE_NOT_FOUND;
    }


    config_init_error err = parse(config_file,config);
    fclose(config_file); // 昨天忘关了？
    return err;

}

