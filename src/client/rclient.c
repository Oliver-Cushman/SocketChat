#include "../../include/client_util.h"

#define PORT 8080
#define SERVER_ADDRESS "127.0.0.1"

int main() {
    
    int clientFd = openClient(SERVER_ADDRESS, PORT);

    for (;;) {
        char readBuffer[256] = recvStringMessage(clientFd, readBuffer, sizeof(readBuffer));
        printf("Received: %s\n", readBuffer);
    }

    return 0;
}