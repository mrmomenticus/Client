#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fstream>
#include <thread>
#include <mutex>
#include <vector>
//Необходимо реализовать клиент-серверное приложение под Linux. 
//Клиент - программа, запускаемая из консоли. 
//Сервер - демон, корректно завершающийся по сигналам SIGTERM и SIGHUP. 
//Клиент должен передать содержимое текстового файла через TCP. 
//Сервер должен принять и сохранить в файл.
void fileReader(char *buffer) {
    std::ifstream file;
    file.open("\\home\\mrmomenticus\\CLionProjects\\client\\file");
    while (true) {
        file.getline(buffer, 1024);
        if (!file.eof()) {
            file.close();
            break;
        }
    }
}
int main() {
    std::mutex m;
    setlocale(LC_ALL, "RUS");
    char buffer[1024];
    std::thread t1([&buffer]() { fileReader(buffer); });
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << buffer[3];
//    int sock =  socket(AF_INET, SOCK_STREAM,0); //Создаем сокет, используем SOCK_STREAM для TCP
//    struct sockaddr_in adr = {0};
//
//    adr.sin_family = AF_INET;
//    adr.sin_port = htons(3425);
//    if(connect(sock, (struct sockaddr *)&adr, sizeof(adr)) < 0) //Проверка на коннект
//        {
//        std::cout << "Не получилось связать\n";
//        exit(2);
//        }
//    listen(sock, 1);



}
