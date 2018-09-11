//
// Created by avsurganov on 9/10/18.
//

#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H

#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <zconf.h>

class Server {
    int server_fd, new_socket, valread, opt, addrlen, port;
    char buffer[1024] = {0};
    struct sockaddr_in address;
public:
    explicit Server (int);
    ~ Server();
    void setValread(int);
    void startServer();
};

#endif //CHAT_SERVER_H


/**
 * Notes: Static variables are unique to each class object.
 */
