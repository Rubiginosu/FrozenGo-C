//
// Created by axoford12 on 8/23/17.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <memory.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include "start.h"
#include "../clog/color.h"
#include "handler.h"

#define MAX_REQUESTS 10

/**
 *
 * @param c
 * 配置文件，主要用于读入port
 * @param socket_fd
 * 套接字描述符
 * @return
 * 返回listen_err类型枚举的错误。
 */
listen_error __daemon_init(config c,int *socket_fd) {
    if(((*socket_fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) < 0)){
        return ERR_SOCKET_INIT;
    }
    int errcode;
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons((__uint16_t )c.port); // 转为大端储存
    // 内存高地址储存低地址，把本身的uint转为通信用
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    color_info_println("Trying to bind port:");
    printf("%ld\n",c.port);
    if((errcode = bind(*socket_fd,(struct sockaddr*)&sin,sizeof(struct sockaddr))) < 0){
        color_err_println("Bind error,code:");
        printf("%d\n",errcode);
        printf("%s",strerror(errno));
        return ERR_SOCKET_BIND;
    }
    if(listen(*socket_fd,MAX_REQUESTS) < 0){
        return ERR_SOCKET_LISTEN;
    }
    color_info_println("Daemon-Panel Socket started !\n");
    return INIT_OK;
}


void handle_connection(config c) {
    int socket_fd = 0;
    int conn_fd;
    int errcode;
    color_info_println("Starting socket...\n");
    if((errcode = __daemon_init(c,&socket_fd)) != INIT_OK){
        color_err_println("Cannot init socket.Errcode:");
        printf("%d",errcode);
    }
    while(1){
        if((conn_fd = accept(socket_fd,(struct sockaddr*)NULL,NULL)) < 0){
            color_err_println("Cannot accept socket_fd..\n");
        }
        pthread_t new_thread;
        frozen_go_message_fd fd;
        fd.conn_fd = conn_fd;
        if(!pthread_create(&new_thread,NULL,(void*)handleReq,&fd)){
            color_err_println("Cannot create thread\n");
            close(socket_fd);
            close(conn_fd);
            return;
        }
    }
}
