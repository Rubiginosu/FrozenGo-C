//
// Created by axoford12 on 8/24/17.
//

#include <memory.h>
#include "handler.h"

const char* RESP_MISSING_ARGUMENTS = "Missing arguments";
void handleReq(frozen_go_message_fd fd) {
    char buf[BUF_LENGTH];
    int n ;
    n = (int)recv(fd.conn_fd,buf,BUF_LENGTH,0);
    buf[n] = '\0';
    printf("%s",buf);
    char* req[3];
    n = 0;
    char* temp = strtok(buf,"|");
    while(temp)
    {

        if(n > 4){
            break;
        }
        req[n] = temp;
        temp = strtok(NULL,"|");
        n++;
    }
    if(n < 4){
        send(fd.conn_fd,RESP_MISSING_ARGUMENTS,strlen(RESP_MISSING_ARGUMENTS),0);
    }
    for (int i = 0; i < 4; ++i) {
        printf("%s,",req[n]);
    }
    close(fd.conn_fd);
}
