#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <bits/socket.h>
#include <fstream>

int main() {

    std::ifstream file;
    char buffer[256];
    int flag = 0;
    setlocale(LC_ALL, "RUS");
    int sock= socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        std::cout << "Не получилось создать сокет\n";
        exit(1);
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        std::cout << "Не получилось связать\n";
        exit(2);
    }
    file.open("/home/mrmomenticus/CLionProjects/Client/test1");
    if (!file.is_open()) { // если файл не открыт
        std::cout << "Файл не может быть открыт!\n";
        exit(0);
    }
    while(!file.eof()) {
        file.read(  buffer, 256);
        int send_result = send(sock, buffer, 256, 0);
        if (send_result <= 0) {
            std::cout << "Не получилось передать данные" << std::endl;
            close(sock);
        }

    }
    std::cout <<"Отправлено";
    file.close();
    close(sock);
    exit(0);
}
