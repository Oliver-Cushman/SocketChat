#ifndef NET_UTIL_H
#define NET_UTIL_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    struct sockaddr_in address;
    socklen_t addressLength;
    int fd;
} Client;  

void initIPv4Address(struct sockaddr_in* address, const char* addressStr, u_int16_t port);

int openSocket();

int sendStringMessage(int fd, const char* message);

char* recvStringMessage(int fd, char* messageBuffer, ssize_t messageBufferSize);

#endif