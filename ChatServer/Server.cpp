//
// Created by avsurganov on 9/10/18.
//

#include "Server.h"

Server::Server (int port) {
   this->port = port;
   opt = 1;
   addrlen = sizeof(address);
}

void Server::setValread (int valread) {
    this->valread = valread;
}

Server::~Server () {
    close(server_fd);
}

void Server::startServer() {
    std::cout << "Listening for connections...\n";
    char hello[1024] = "Howdy there, I am the server\0";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    std::cout << "Connection Established\n";
    while(true) {
        memset(buffer, 0, 1024);
        setValread((int) read(new_socket, buffer, 1024));
        if (valread != 0) {
            printf("%s\n", buffer);
            if (strcmp(buffer, "exit") == 0) {
                send(new_socket, "Goodbye!", strlen("Goodbye!"), 0);
            } else {
                send(new_socket, hello, strlen(hello), 0);
            }
        } else {
            std::cout << "Connection Terminated.\n";
            std::cout << "Server shuting down.";
            return;
        }
    }
}