#include <stdio.h>

#define PORT 8080
#define SERVER_ADDRESS "127.0.0.1"

int main() {

    int clientFd = openClient(SERVER_ADDRESS, PORT);
    for (;;) {
        char writeBuffer[256];
        scanf("%255s", writeBuffer);
        sendStringMessage(clientFd, writeBuffer);
    }
    return 0;
}