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