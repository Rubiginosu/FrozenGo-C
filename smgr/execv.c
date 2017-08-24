//
// Created by axoford12 on 8/24/17.
//

#include "execv.h"
err_start_server exec_command(int *fd, char *command, char **args) {
    int out[2];
    int in[2];
    if(pipe(out) != 0) return ERR_INIT_PIPE_OUT;
    if(pipe(in) != 0 ) return ERR_INIT_PIPE_IN ;
    int child_pid = fork(); // Fork出子进程
    if (child_pid < 0) {
        return ERR_FORK;
    }
    if (child_pid == 0) {
        dup2(in[1], 0); // 复制stdin 文件描述符
        dup2(out[1], 1); // 复制stdout 文件描述符
        close(out[0]); // 关掉输出流
        close(in[0]); // 关掉输入流，子进程只留下单向流即可
        execv(command,args); // 装载要执行的程序改头换面～

    }
    close(out[1]);
    close(in[1]);
    fd[0] = out[0]; // 包装一番return出去
    fd[1] = in[0];
}