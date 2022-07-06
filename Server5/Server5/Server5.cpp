#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#include <winsock2.h>
#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <atomic>


using namespace std;
const char* nameMutex = "SERVER";
HANDLE Mutex;
mutex mt;
//HANDLE mtx = CreateMutex(NULL, TRUE, NULL);
ofstream fout;
struct playerC {
    SOCKET socket;
    atomic<bool> isPlay;
    char name[12];
};
playerC Connections[1000];
atomic<int> amountOfBadMes = 0;
atomic<int> amountOfGoodMes = 0;
atomic<int> counter = 0;
int allPlayers = 0;
void getMes(int i) {
    int m;
    char mes[256];
    while (1) {
        if (!Connections[i].isPlay)
            return;
        //m = recv(Connections[i].socket, mes, sizeof(mes), NULL);
        if (recv(Connections[i].socket, mes, sizeof(mes), NULL) > 0) {
            mt.lock();
            if (mes[0] == 'G' || mes[0] == 'B')
                ++amountOfGoodMes;
            else
                ++amountOfBadMes;
            fout << Connections[i].name  <<": "<< mes << endl;
            cout << Connections[i].name << ": " << mes << endl;
            mt.unlock();
        }
        else {  
            Connections[i].isPlay = FALSE;
            if (!closesocket(Connections[i].socket))
                --counter;  
            return;
        }
    }
}
void sendMes(int i) {
    char mes[5] = "lags";
    while (1) {
        if (!Connections[i].isPlay)
            return;
        if (counter > 4) {
            if (send(Connections[i].socket, mes, sizeof(mes), NULL) == SOCKET_ERROR) {
                return;
            }
        }
        Sleep(2000*(rand()%15+2)+rand()%1000);
    }
}
void Accept(SOCKADDR_IN addr, int size, SOCKET sListen) {
    SOCKET newConnection;
    for (int i = 0; i < 1000; ++i) {
        if (!(newConnection = accept(sListen, (SOCKADDR*)&addr, &size)) && counter < 10) { //Извлечение запроса на подключение сокета
            cout << "ERROR";
        }
        else {
            //cout << "Client Connected" << endl;
            Connections[i].socket = newConnection;
            Connections[i].isPlay = TRUE;
            recv(Connections[i].socket, Connections[i].name, sizeof(Connections[i].name), NULL);
            //cout << newConnection << endl;
            ++allPlayers;
            ++counter;
            thread t = thread(getMes, i);
            thread t1 = thread(sendMes, i);
            t.detach();
            t1.detach();
            
        }
        if (counter >= 10) {
            while (counter > 5) {
                int i = rand() % allPlayers;
                if (Connections[i].isPlay) {
                    Connections[i].isPlay = FALSE;
                    closesocket(Connections[i].socket);
                    --counter;
                }
            }
        }
    }
}
void start(SOCKADDR_IN addr, int size, SOCKET sListen) {
    thread t = thread(Accept, addr, size, sListen);
    t.detach();
    Sleep(20000);
    //return;
    while (1) {
        if (counter == 0)
            return;
        Sleep(2000);
    }
}
int main()
{
    Mutex = CreateMutexA(NULL, TRUE, nameMutex);
    if (GetLastError()) {
        cout << "ERROR: Maybe the server was started" << endl;
        system("PAUSE");
        return 0;
    }
    fout.open("Chat.txt");
    setlocale(LC_ALL, "Russian");
    WSAData wsaData;  //создаем структуру для загрузки
    WORD DLLVersion = MAKEWORD(2, 1);   //Запрос версии winsock
    if (WSAStartup(DLLVersion, &wsaData)) { //Загрузка библиотеки
        exit(1);
    }
    SOCKADDR_IN addr; // структура для описания сокета
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //адрес
    addr.sin_port = htons(1111); //порт
    addr.sin_family = AF_INET; //семейство протоколов

    SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
    bind(sListen, (SOCKADDR*)&addr, sizeofaddr);  //Привязка адреса сокету
    listen(sListen, 100); //Запуск прослушивания, макс колво запросов, ожидающих обработки
    SOCKET newConnection;
    start(addr, sizeofaddr, sListen);
    cout << "Bad mes: " << amountOfBadMes << endl;
    cout << "Good mes: " << amountOfGoodMes << endl;
    fout << "Bad mes: " << amountOfBadMes << endl;
    fout << "Good mes: " << amountOfGoodMes << endl;
    fout.close();
    for (int i = 0; i < allPlayers; ++i) {
        closesocket(Connections[i].socket); // Закрытие созданного сокета
    }
    CloseHandle(Mutex);
    closesocket(sListen);
    cout << "Last Error " << WSAGetLastError() << endl;
    WSACleanup(); // Деиницилизация библиотеки Winsock
    //system("pause");
    return 0;
}