#ifndef NET_UTIL_H
#define NET_UTIL_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

struct Client {
    struct sockaddr_in address;
    socklen_t addressLength;
    int fd;
};

struct sockaddr_in initIPv4Address(char *addressStr, u_int16_t port);

int openSocket();

#endif