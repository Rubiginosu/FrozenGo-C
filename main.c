/**
 * by Axoford12
 */
#include <stdlib.h>
#include "clog/color.h"
#include "cnf/cnf.h"
#include "smgr/start.h"
#include "utils/md5_sum.h"
#include "utils/md5_cmp.h"
#include <openssl/md5.h>
#include <memory.h>

void banner(){
    color_special_println("FrozenGo Daemon Started\n");
}


int main() {
    config c;
    banner();
//    if(getuid() != 0){
//        color_err_println("Need root permission.\n");
//        exit(1);
//    }
    color_info_println("Initialing Configuration files.\n");
    if(config_init(&c)) {
        color_err_println("Error cannot read config file.\n");
        exit(2);;
    }
    color_info_println("Starting daemon-panel socket.\n");
    handle_connection(c);

    return 0;
}
