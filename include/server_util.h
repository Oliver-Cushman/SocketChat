#ifndef SERVER_UTIL_H
#define SERVER_UTIL_H

#include "net_util.h"

int openServer(char *addressStr, u_int16_t port, u_int8_t maxConnections);

Client acceptClient(int serverFd);

#endif