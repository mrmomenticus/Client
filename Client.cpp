#include "Client.h"
void Client::signalHandler(int sig) {
    close(sock);
    delete buffer;
    exit(sig);
}
void Client::connecting() {
    signal(SIGTERM, signalHandler ) ;
    signal(SIGHUP, signalHandler);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        std::cout << "Не получилось связать\n";
        close(sock);
        delete buffer;
        exit(2);
    }
    sendingFile();
}
void Client::readFile() {
    while(!file.is_open()){
        std::string str;
        std::cout <<"Введите путь файла: ";
        std::cin >> str;
        file.open(str);
        if (!file.is_open()) { // если файл не открыт
            std::cout << "Файл не может быть открыт по данному пути!\n";
        }
    }
}
void Client::sendingFile() {
    readFile();
    while(true) {
        file.read(  buffer, BUFFER_SIZE);
        if (file.eof()){
            break;
        }
        int send_result = send(sock, buffer, BUFFER_SIZE, 0);
        if (send_result <= 0) {
            std::cout << "Не получилось передать данные" << std::endl;
            close(sock);
            delete buffer;
            exit(0);
        }
    }
    std::cout <<"Отправлено";
    file.close();
    close(sock);
}
