#ifndef NET_UTIL_H
#define NET_UTIL_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

struct Client {
    struct sockaddr_in address;
    socklen_t addressLength;
    int fd;
};

struct sockaddr_in initIPv4Address(char *addressStr, u_int16_t port);

int openSocket();

int sendStringMessage(int fd, char *message);

char* recvStringMessage(int fd, char *messageBuffer, ssize_t messageBufferSize);

#endif