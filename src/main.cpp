//#include "HostPortSocket.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "HostPortSocket.h"


unsigned int port = 9876;
const char ip[] = "192.168.0.1";

//sockpp::tcp_connector client;

HostPortSocket wifi_port;
std::vector<float> data(32);

int main() {
    if (!wifi_port.begin(ip, port, HostPortSocket::HEADER, HostPortSocket::TERMINATOR, 10000)) {
        printf("Unable to connect\n");
        return -1;
    }
    while (1) {
        if (wifi_port.read((unsigned char*) data.data(), 4*32)) {
            for (int i = 0; i < 32; ++i) {
                printf("%.3f\t", data[i]);
            }
            printf("\n");
        }

    }

    return 0;
}