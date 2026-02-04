#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080
#define SERVER_ADDRESS "127.0.0.1"

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
    int clientFd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientFd == -1) {
        perror("Unable to create socket");
        return -1;
    }
    int connectionStatus = connect(clientFd, (struct sockaddr*) &serverAddress, serverAddressLength);
    if (connectionStatus == -1) {
        perror("Connection failed");
        return -1;
    }
    char writeBuffer[256];
    scanf("%255s", writeBuffer);
    if (write(clientFd, writeBuffer, strlen(writeBuffer)) == -1) {
        perror("Failed to send");
        return -1;
    }
    char readBuffer[256];
    if (read(clientFd, readBuffer, sizeof(readBuffer)) == -1) {
        perror("Failed to read");
        return -1;
    }
    printf("Response: %s\n", readBuffer);
    printf("Client process complete!\n");
    close(clientFd);
    return 0;
}