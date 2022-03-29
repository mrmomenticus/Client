#ifndef CLIENT_SERVERDAEMON_CLIENT_H
#define CLIENT_SERVERDAEMON_CLIENT_H
#define  BUFFER_SIZE 16
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <bits/socket.h>
#include <fstream>
#include <csignal>
class Client {
    std::ifstream file;
    static char inline *buffer = new char(BUFFER_SIZE);
    static int inline sock= socket(AF_INET, SOCK_STREAM, 0);
    static void signalHandler(int sig);
    void readFile();
    void sendingFile();
public:
    void connecting();
};


#endif //CLIENT_SERVERDAEMON_CLIENT_H
