#include <unistd.h>
#include <string.h>
#include "../../include/server_util.h"

#define SERVER_ADDRESS "127.0.0.1"
#define PORT 8080
#define MAX_CONNECTIONS 2

int main() {
    int fd = openServer(SERVER_ADDRESS, PORT, MAX_CONNECTIONS);
    // Accept clients
    struct Client clients[MAX_CONNECTIONS];
    printf("Waiting for %d clients\n", MAX_CONNECTIONS);
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        clients[i] = acceptClient(fd);
        if (i + 1 >= MAX_CONNECTIONS) {
            printf("Connection successful, beginning session\n");
        } else {
            printf("Connection successful, waiting for %d more connection(s)\n", MAX_CONNECTIONS - (i + 1));
        }
    }
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        close(clients[i].fd);
    }
    close(fd);
    return 0;
}