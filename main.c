/**
 * by Axoford12
 */
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include "clog/color.h"

void banner(){
    color_special_println("FrozenGo Daemon Started");
}


int main() {
    banner();
    if(getuid() != 0){
        color_err_println("Need root permission.");
        exit(1);
    }
    return 0;
}
