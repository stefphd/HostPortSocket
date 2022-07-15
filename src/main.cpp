//#include "HostPortTCP.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "HostPortTCP.h"

unsigned short port = 9876;
const char ip[] = "192.168.0.1";

//sockpp::tcp_connector client;

HostPortTCP wifi_port;
std::vector<float> data(32);

int main() {
    if (!wifi_port.begin(ip, port, HostPortTCP::HEADER, HostPortTCP::TERMINATOR, 10000)) {
        printf("Unable to connect\n");
        return -1;
    }
    if (!wifi_port.isInit()) {
        printf("Issue in device connection\n");
        return -1;
    }

    printf("Connected\n");
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