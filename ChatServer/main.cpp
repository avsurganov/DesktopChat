//
// Created by avsurganov on 9/10/18.
//
#include <zconf.h>
#include "Server.h"

int main () {
    Server s(8080);
    s.startServer();
    return 0;
}