//
// Created by axoford12 on 8/23/17.
//

#include <sys/wait.h>
#include "start.h"

#define RESULT_SIZE 1024
err_start_server start_server(int *fd, char *command, char **args) {
    int out[2];
    int in[2];
    if(pipe(out) != 0) return ERR_INIT_PIPE_OUT;
    if(pipe(in) != 0 ) return ERR_INIT_PIPE_IN ;
    int child_pid = fork();
    if (child_pid < 0) {
        return ERR_FORK;
    }
    if (child_pid == 0) {
        dup2(in[1], 0);
        dup2(out[1], 1);
        close(out[0]);
        close(in[0]);
        execv(command,args);

    }
    close(out[1]);
    close(in[1]);
    fd[0] = out[0];
    fd[1] = in[0];
}
