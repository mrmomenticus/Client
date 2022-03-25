#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <bits/socket.h>
#include <fstream>
#define  BUFFER_SIZE 16
int main() {

    std::ifstream file;
    char *buffer = new char(BUFFER_SIZE);
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
    file.open("/home/mrmomenticus/CLionProjects/Client/test");
    if (!file.is_open()) { // если файл не открыт
        std::cout << "Файл не может быть открыт!\n";
        exit(0);
    }
    while(true) {
        file.read(  buffer, BUFFER_SIZE);
        if (file.eof()){

            break;
        }
        int send_result = send(sock, buffer, BUFFER_SIZE, 0);
        if (send_result <= 0) {
            std::cout << "Не получилось передать данные" << std::endl;
            exit(0);
        }

    }


    std::cout <<"Отправлено";
    file.close();
    close(sock);
}
