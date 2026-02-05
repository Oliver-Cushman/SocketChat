#include "../../include/net_util.h"

struct sockaddr_in initIPv4Address(char *addressStr, u_int16_t port) {
    struct sockaddr_in address;

    if (inet_pton(AF_INET, addressStr, &(address.sin_addr.s_addr)) != 1) 
        perror("Invalid IP address");

    // IPv4
    address.sin_family = AF_INET;
    // Port
    address.sin_port = htons(port);

    return address;
}

int openSocket() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd == -1)
        perror("Unable to create socket");

    return fd;
}

int sendStringMessage(int fd, char *message) {
    int bytesSent = send(fd, message, strlen(message), 0);

    if (bytesSent == -1) 
        perror("Failed to send message");
    
    return bytesSent;
}

char* recvStringMessage(int fd, char *messageBuffer, ssize_t messageBufferSize) {
    ssize_t bytesRead = recv(fd, messageBuffer, messageBufferSize, 0);

    if (bytesRead == -1)
        perror("Failed to read message");

    return messageBuffer;
}