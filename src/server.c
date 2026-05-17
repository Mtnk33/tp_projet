#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int main() {
    int listenfd, connfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(listenfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(listenfd, 5);

    printf("Serveur actif sur port %d...\n", PORT);

    while (1) {
        connfd = accept(listenfd, NULL, NULL);

        read(connfd, buffer, sizeof(buffer));
        printf("Message reçu: %s\n", buffer);

        write(connfd, "Reçu\n", 5);

        close(connfd);
    }

    return 0;
}
