#include "../../include/server_util.h"

int openServer(char *addressStr, u_int16_t port, u_int8_t maxConnections) {
    struct sockaddr_in address = initIPv4Address(addressStr, port);
    int fd = openSocket();

    int status = -1;
    while (status = bind(fd, (struct sockaddr*) &address, sizeof(address)) == -1)
        printf("Unable to bind server address\n");

    while (status = listen(fd, maxConnections) == -1)
        printf("Unable to start listening for connections\n");

    return status;
}

struct Client acceptClient(int serverFd) {
    struct Client client;

    while (client.fd = accept(serverFd, (struct sockaddr*) &(client.address), &(client.addressLength)) == -1)
        printf("Unable to accept client\n");

    return client;
}