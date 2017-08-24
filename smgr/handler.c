//
// Created by axoford12 on 8/24/17.
//

#include <memory.h>
#include <errno.h>
#include <stdlib.h>
#include "handler.h"
#include "../clog/color.h"
#define ARGUMENTS_NUM 4
#include "start.h"

const char* RESP_MISSING_ARGUMENTS = "Missing arguments";
void handleReq(frozen_go_message_fd* fd) {
    char buf[BUF_LENGTH];
    int  file_d = fd->conn_fd;
    free(fd);
    ssize_t n ;
    if((n = recv(file_d,buf,BUF_LENGTH,0)) < 0){
        color_info_println("Read error\n");
        strerror(errno);
    }
    buf[n] = '\0';
    printf("%s\n",buf);
    char* req[ARGUMENTS_NUM];
    n = 0;
    char* temp = strtok(buf,"|");
    while(temp)
    {

        if(n >= ARGUMENTS_NUM){
            break;
        }
        req[n] = temp;
        temp = strtok(NULL,"|");
        n++;
    }
    if(n < ARGUMENTS_NUM){
        send(file_d,RESP_MISSING_ARGUMENTS,strlen(RESP_MISSING_ARGUMENTS),0);
    }
    close(file_d);
}
