#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <bits/socket.h>
#include <fstream>

class ReadAndTake{
    char m_buffer[1024];
    std::mutex m;
public:
    void reader() { //разбиваем считанный файл на пакеты
        std::ifstream file;
        file.open("/home/mrmomenticus/CLionProjects/Client/test");
        if (!file.is_open()) // если файл не открыт
            std::cout << "Файл не может быть открыт!\n"; // сообщить об этом
        else
        {
            file.getline(m_buffer, 1024);
            std::cout << m_buffer;
            file.close();
        }
    }
        void take(){
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
            m.lock();
            int send_result = send(sock, m_buffer, 1024, 0);
            if(send_result <= 0)
                std::cout << "Не получилось передать данные" << std::endl;
            m.unlock();

            close(sock);
    }
};
int main() {
    setlocale(LC_ALL, "RUS");
    ReadAndTake objecktReadandTake;
    std::thread t1([&]() { objecktReadandTake.reader(); });

   // std::this_thread::sleep_for(std::chrono::milliseconds(1000));





}
