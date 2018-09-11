//
// Created by avsurganov on 9/11/18.
//

#include "Client.h"

Client::Client(const char* ip, int port) {
    this->ip = ip;
    this->port = port;
}

void Client::setValread(int valread) {
    this->valread = valread;
}

Client::~Client() {
    close(sock);
}

void Client::sendMessages() {
    const char *buf;
    std::string input;
    std::string exit = "exit";

    while(true) {
        if (input.compare(exit) != 0) {
            std::cout << "Enter Msg: ";
            std::getline(std::cin, input);
            buf = input.c_str();
            if (strlen(buf) != 0) {
                send(sock, buf, strlen(buf), 0);
                setValread((int) read(sock, buffer, 1024));
                printf("%s\n", buffer);
            }
        } else {
            std::cout << "Closing Connection with Server\n";
            return;
        }
    }
}

void Client::startConnection() {
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip, &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return;
    }

    sendMessages();
}

