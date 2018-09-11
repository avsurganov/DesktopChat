#include <iostream>
#include "Client.h"

int main() {
    Client c("127.0.0.1", 8080);
    c.startConnection();
    return 0;
}