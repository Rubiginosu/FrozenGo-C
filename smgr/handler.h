//
// Created by axoford12 on 8/24/17.
//

#ifndef FROZENGO_C_HANDLER_H
#define FROZENGO_C_HANDLER_H
/**
 * BUF_LENGTH  定义了缓冲区的长度。
 */
#define BUF_LENGTH 2048

#include <sys/socket.h>
#include "start.h"

/**
 *
 * @param fd
 * 创建线程包装的描述符
 * @return
 */
void handleReq(frozen_go_message_fd fd);

#endif //FROZENGO_C_HANDLER_H
