//
// Created by axoford12 on 8/24/17.
//

#include <memory.h>
#include <errno.h>
#include <stdlib.h>
#include "handler.h"
#include "../clog/color.h"
#include "start.h"
#include "../utils/md5_cmp.h"
#include "../utils/md5_sum.h"

#define ARGUMENTS_NUM 4

const char *RESP_MISSING_ARGUMENTS = "Missing arguments";


/**
 *
 * @param fd
 * 创建线程包装的描述符
 * @return
 */
void __process_req(frozen_go_message_fd *fd) {
    char buf[BUF_LENGTH];
    int file_d = fd->conn_fd;
    char *key = fd->key_sum;
    free(fd);
    ssize_t n;
    if ((n = recv(file_d, buf, BUF_LENGTH, 0)) < 0) {
        color_info_println("Read error\n");
        strerror(errno);
    }
    buf[n] = '\0';
    printf("%s\n", buf);
    char *req[ARGUMENTS_NUM];
    n = 0;
    char *temp = strtok(buf, "|");
    while (temp) {

        if (n >= ARGUMENTS_NUM) {
            break;
        }
        req[n] = temp;
        temp = strtok(NULL, "|");
        n++;
    }
    if (n < ARGUMENTS_NUM) {
        send(file_d, RESP_MISSING_ARGUMENTS, strlen(RESP_MISSING_ARGUMENTS), 0);
    }
    char *resp;
    resp = req_handle_req(key, req);
    write(file_d, resp, strlen(resp));

    close(file_d);
}

char *req_handle_req(char *key, char *req[ARGUMENTS_NUM]) {
    color_info_println("Due to authenticating this client.\n");
    color_info_println("Key_Sum:");
    printf("%s\n", key);
    color_info_println("Req_Info:");
    printf("%s\n", req[0]);
    color_info_println("Req_Sum:");
    printf("%s\n", md5_sum_get(req[0]));
    if (!str_md5_cmp(req[0], key)) {
        return "Authentic error";
    }
    return "OK";
    // TODO 业务逻辑什么鬼的

}
