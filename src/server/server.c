#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_CONNECTIONS 2
#define PORT 8080
#define SERVER_ADDRESS "127.0.0.1"

struct Client {
    struct sockaddr_in address;
    socklen_t addressLength;
    int fd;
};

int main() {
    // Server IP address
    struct sockaddr_in serverAddress;
    socklen_t serverAddressLength = sizeof(serverAddress);
    if (inet_pton(AF_INET, SERVER_ADDRESS, &(serverAddress.sin_addr.s_addr)) != 1) {
        perror("Invalid IP address");
        return -1;
    }
    // IPv4
    serverAddress.sin_family = AF_INET;
    // Port 8080
    serverAddress.sin_port = htons(PORT);
    // Create socket file descriptor
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd == -1) {
        perror("Unable to create socket");
        return -1;
    }
    // Bind server address to socket
    if (bind(serverFd, (struct sockaddr*) &serverAddress, serverAddressLength) == -1) {
        perror("Unable to bind server address");
        return -1;
    }
    // Prepare to listen for connections
    if (listen(serverFd, MAX_CONNECTIONS) == -1) {
        perror("Unable to start listening for connections");
        return -1;
    }
    // Accept clients
    struct Client clients[MAX_CONNECTIONS];
    printf("Waiting for %d clients\n", MAX_CONNECTIONS);
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        clients[i].fd = -1;
        while (clients[i].fd = accept(
            serverFd, 
            (struct sockaddr*) &(clients[i].address), 
            &(clients[i].addressLength)) == -1) {
                printf("Connection from client %d failed. Retrying...\n", i + 1);
        }
        if (i + 1 >= MAX_CONNECTIONS) {
            printf("Connection successful, beginning session\n");
        } else {
            printf("Connection successful, waiting for %d more connection(s)\n", MAX_CONNECTIONS - (i + 1));
        }
    }
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        close(clients[i].fd);
    }
    close(serverFd);
    return 0;
}