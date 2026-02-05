#include "../../include/client_util.h"

int openClient(char *serverAddressStr, u_int16_t port) {
    struct sockaddr_in serverAddress = initIPv4Address(serverAddressStr, port);
    int fd = openSocket();

    int status = -1;
    while (status = connect(fd, (struct sockaddr*) &serverAddress, sizeof(serverAddress) == -1))
        printf("Connection failed... Retrying\n");

    return status;
}