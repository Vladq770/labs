#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#include <winsock2.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <thread>
#include <atomic>

using namespace std;
struct Player {
    SOCKET connection;
    atomic<int> patience;
    char name[12];
};
Player player;
void goodMessage() {
    int random;
    int Time = time(NULL);
    char mesGood[3][15] = { "GOOD GAME!!!", "BEAUTIFUL GAME", "GL HF!" };
    while (1) {
        random = rand() % 3;
        if (time(NULL) - Time >= 10 && player.patience) {
            if (send(player.connection, mesGood[random], sizeof(mesGood[random]), NULL) == -1)
                return;
            Time = time(NULL);
        }
        Sleep(2000);
    }
}
void getLags() {
    thread t2(goodMessage);
    t2.detach();
    char mes[256];
    char mesLag[6] = "lags!";
    while (1) {
        if (recv(player.connection, mes, sizeof(mes), NULL) > 0) {
            if (player.patience > 0) {
                --player.patience;
            }
            if (player.patience == 0)
                send(player.connection, mesLag, sizeof(mesLag), NULL);
        }
        else {
            return;
        }
    }
}

int main()
{
    srand(time(NULL));
    int s = 5 + rand() % 7;
    for(int i = 0; i < s; ++i)
        player.name[i] = ((char)(63 + rand() % 60));
    player.name[s] = '\0';
    player.patience = rand() % 6+1;
    cout << player.name << endl;
    setlocale(LC_ALL, "Russian");
    WSAData wsaData;  //создаем структуру для загрузки
    WORD DLLVersion = MAKEWORD(2, 1);  //Запрос версии winsock
    if (WSAStartup(DLLVersion, &wsaData)) {  //Загрузка библиотеки
        exit(1);
    }
    SOCKADDR_IN addr; // структура для описания сокета
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //адрес
    addr.sin_port = htons(1111); //порт
    addr.sin_family = AF_INET; //семейство протоколов
  //player.connection = socket(AF_INET, SOCK_STREAM, NULL);
    bool firstConnection = 1;
    char lag1[8] = "LAGS!!!";
    char lag2[18] = "The worst game!!!";
    
    while (1) {
        player.connection = socket(AF_INET, SOCK_STREAM, NULL);
        Sleep(100);
        if (connect(player.connection, (SOCKADDR*)&addr, sizeofaddr)) {
            cout << "Connection error" << endl;
            Sleep(1000);
        }
        else {
            send(player.connection, player.name, sizeof(player.name), NULL);
            cout << "Successful connection" << endl;
            if (!firstConnection) {
                cout << "!firstConnection" << endl;
                send(player.connection, lag1, sizeof(lag1), NULL);
                Sleep(10);
                send(player.connection, lag2, sizeof(lag2), NULL);
            }
            Sleep(5000);
            firstConnection = 0;
            thread th1(getLags);
            th1.join();
        }
        if (rand() % 2) {
            cout << "EXIT" << endl;
            break;
        }
    }
    closesocket(player.connection);
    cout << "Last Error " << WSAGetLastError();
    WSACleanup(); // Деиницилизация библиотеки Winsock

    system("PAUSE");
    return 0;
}
