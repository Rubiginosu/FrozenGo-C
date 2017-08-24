//
// Created by axoford12 on 8/23/17.
//

#ifndef FROZENGO_C_START_H
#define FROZENGO_C_START_H

#include <unistd.h>
#include "../cnf/cnf.h"
typedef enum{
    INIT_OK = 0,
    ERR_SOCKET_INIT,
    ERR_SOCKET_BIND,
    ERR_SOCKET_LISTEN,

} listen_error;

typedef struct{
    int conn_fd;
    char* key_sum;
}frozen_go_message_fd;
void handle_connection(config c);
#endif //FROZENGO_C_START_H
