//
// Created by axoford12 on 8/23/17.
//

#include <sys/wait.h>
#include <stdio.h>
#include "start.h"
#include "../clog/color.h"
#define RESULT_SIZE 1024
void start_server(){
    int fd[2];
    pipe(fd);
    char result[RESULT_SIZE];
    int child_pid = fork();
    if(child_pid < 0){
        color_err_println("Fork failed.");
    } else if (child_pid == 0){
        close(1);
        dup2(fd[1],1);
        close(fd[0]);
        execlp("ls","ls");
    }
    wait(NULL);
}
