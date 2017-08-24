//
// Created by axoford12 on 8/24/17.
//

#include "color.h"
#include<stdio.h>
enum method_type{
    FR_RED = 31,
    FR_GREEN,
    FR_YELLOW,
    FR_BLUE,
    FR_PURPLE,
    FR_CYAN,
};
void color_print(enum method_type type, char *message, char *section){
    printf("\033[1;%dm[%s]\033[0m",type,section);
    printf("%s",message);
}

void color_promt_println(char *message) {
    color_print(FR_GREEN, message, "Prompt");
}

void color_err_println(char *err) {
    color_print(FR_RED, err, "Error");
}

void color_special_println(char *spe) {
    color_print(FR_CYAN, spe, "FrozenGo");
}

void color_info_println(char *info) {
    color_print(FR_BLUE, info, "Info");
}
