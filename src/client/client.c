#include <unistd.h>
#include <string.h>
#include "../../include/client_util.h"

#define PORT 8080
#define SERVER_ADDRESS "127.0.0.1"

int main() {
    int clientFd = openClient(SERVER_ADDRESS, PORT);
    
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