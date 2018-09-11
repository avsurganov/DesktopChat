//
// Created by avsurganov on 9/11/18.
//

#ifndef CHATCLIENT_CLIENT_H
#define CHATCLIENT_CLIENT_H

#include <iostream>
#include <cstdio>
#include <sys/socket.h>
#include <sys/types.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>
#include <string>
#include <zconf.h>
#include <arpa/inet.h>

class Client {
   struct sockaddr_in address, serv_addr;
   int sock = 0;
   int valread, port;
   const char* ip;
   char buffer[1024] = {0};
public:
    Client (const char*, int);
    void startConnection();
    void setValread(int);
    void sendMessages();
    ~Client();
};


#endif //CHATCLIENT_CLIENT_H

