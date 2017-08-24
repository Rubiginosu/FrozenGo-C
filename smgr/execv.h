//
// Created by axoford12 on 8/24/17.
//

#ifndef FROZENGO_C_EXECV_H
#define FROZENGO_C_EXECV_H
#include <unistd.h>
typedef enum {
    ERR_INIT_PIPE_OUT = 1,
    ERR_INIT_PIPE_IN,
    ERR_FORK,
}err_start_server;

/**
 * 本函数为fork-pipe封装，提供了运行一个新进程并提供输入输出文件描述符的封装函数
 * 用于启动一个exec_config类型的服务器。
 * @param fd
 * 该函数会把Stdout/Stderr 文件描述符存入fd[0]
 * 把Stdin文件描述符存入fd[1]
 * @param command
 * @param args
 * command && args是执行execvp的参数。
 * 程序在fork中的子进程来调用execvp。
 * @return 返回一个错误
 */
err_start_server exec_command(int fd[2], char *command, char **args);
#endif //FROZENGO_C_EXECV_H
