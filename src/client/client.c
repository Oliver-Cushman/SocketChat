#include "../../include/client_util.h"

#define PORT 8080
#define SERVER_ADDRESS "127.0.0.1"

int main() {
    int clientFd = openClient(SERVER_ADDRESS, PORT);
    
    char writeBuffer[256];
    scanf("%255s", writeBuffer);
    sendStringMessage(clientFd, writeBuffer);
    char readBuffer[256] = recvStringMessage(clientFd, readBuffer, sizeof(readBuffer));
    printf("Response: %s\n", readBuffer);
    printf("Client process complete!\n");
    close(clientFd);
    return 0;
}