#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#include <winsock2.h>
#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <algorithm>
#include <thread>
using namespace std;


struct bankAccount {
    int id;
    string pasword;
    int balance;
    int lastOperation[5];
    int deposit;
    int credit;
};
bool cmp(bankAccount a, bankAccount b) {
    return a.id < b.id;
}
mutex mt;
int sizeOfData = 2;
bankAccount dataBase[2];
SOCKET Connections[100];
int counter = 0;
void printToData() {
    ofstream fout;
    fout.open("database.txt", std::ofstream::out | std::ofstream::trunc);
    for (int i = 0; i < sizeOfData; ++i) {
        fout << dataBase[i].id << endl;
        fout << dataBase[i].pasword << endl;
        fout << dataBase[i].balance << endl;
        fout << dataBase[i].deposit << endl;
        fout << dataBase[i].credit << endl;
        for (int j = 0; j < 5; ++j) {
            fout << dataBase[i].lastOperation[j] << endl;
        }
        fout << endl;
    }
    fout.close();
    return;
}
void ClientHandler(int x, ofstream& foutLog) {
    char req[256];
    char temp[256];
    int id;
    int num;
    string pasword;
    int request;
    char sLogin[2] = "s";
    char err0[7] = "0";
    char err1[13] = "1";
    int ind = -1;
    while (1) {
        if (recv(Connections[x], req, sizeof(req), NULL) == 0) {
            cout << req << endl;
            Sleep(1000);
            break;
        }
        int i = 0;
        int j = 0;
        if (req[0] >= '1' && req[0] <= '9') {
            while (req[i] != '/')
                temp[i] = req[i++];
            temp[i++] = '\0';
            id = atoi(temp);
            while (req[i + j] != '\0')
                temp[j] = req[i + j++];
            temp[j++] = '\0';
            pasword = temp;
            j += i;
            i = 0;
            while (req[i + j] != '\0')
                temp[i] = req[j + i++];
            temp[i] = '\0';
            request = int(temp[0]);
            i = -1;
            cout << id << endl << pasword << endl << request << endl;
            if (id<dataBase[0].id || id > dataBase[1].id) {
                mt.lock();
                foutLog << "Попытка подключения: неверное ID" << endl;
                mt.unlock();
                send(Connections[x], err0, sizeof(err0), NULL);
                continue;
            }
            for (int k = 0; k < 10; ++k) {
                if (dataBase[k].id == id) {
                    i = k;
                    break;
                }
            }
            if (i == -1) {
                mt.lock();
                foutLog << "Попытка подключения: неверное ID" << endl;
                mt.unlock();
                send(Connections[x], err0, sizeof(err0), NULL);
                continue;
            }
            if (dataBase[i].pasword != pasword) {
                mt.lock();
                foutLog << "Попытка подключения: неверный пароль" << endl;
                mt.unlock();
                send(Connections[x], err1, sizeof(err1), NULL);
                continue;
            }
            ind = i;
            mt.lock();
            foutLog << "Попытка подключения: ID " << id << " подключен" << endl;
            mt.unlock();
            send(Connections[x], sLogin, sizeof(sLogin), NULL);
            itoa(dataBase[i].balance, temp, 10);
            send(Connections[x], temp, sizeof(temp), NULL);
            itoa(dataBase[i].deposit, temp, 10);
            send(Connections[x], temp, sizeof(temp), NULL);
            itoa(dataBase[i].credit, temp, 10);
            send(Connections[x], temp, sizeof(temp), NULL);
            for (int k = 0; k < 5; ++k) {
                itoa(dataBase[i].lastOperation[k], temp, 10);
                send(Connections[x], temp, sizeof(temp), NULL);
            }
            continue;
        }
        else if (req[0] == 'q') {
            int raz;
            while (req[1+i] != '/')
                temp[i] = req[1+i++];
            temp[i++] = '\0';
            ++i;
            num = atoi(temp);
            raz = num - dataBase[ind].balance;
            dataBase[ind].balance = num;
            while (req[i+j] != '\0')
                temp[j] = req[i+j++];
            temp[j] = '\0';
            num = atoi(temp);
            dataBase[ind].deposit = num;
            mt.lock();
            foutLog << "ID: " << dataBase[ind].id << ": перевод на баланс с вклада " << raz << " RUB" << endl;
            printToData();
            mt.unlock();
        }
        else if (req[0] == 'w') {
            int raz;
            while (req[1+i] != '/')
                temp[i] = req[1+i++];
            temp[i++] = '\0';
            ++i;
            num = atoi(temp);
            raz = dataBase[ind].balance - num;
            dataBase[ind].balance = num;
            while (req[i + j] != '\0')
                temp[j] = req[i + j++];
            temp[j] = '\0';
            num = atoi(temp);
            dataBase[ind].deposit = num;
            mt.lock();
            foutLog << "ID: " << dataBase[ind].id << ": перевод на вклад с баланса " << raz << " RUB" << endl;
            printToData();
            mt.unlock();
        }
        else if (req[0] == 'e') {
            int last;
            while (req[1 + i] != '/')
                temp[i] = req[1 + i++];
            temp[i++] = '\0';
            ++i;
            num = atoi(temp);
            dataBase[ind].balance = num;
            while (req[i + j] != '\0')
                temp[j] = req[i + j++];
            temp[j] = '\0';
            num = atoi(temp);
            last = num - dataBase[ind].credit;
            dataBase[ind].credit = num;
            for (int k = 0; k < 4; ++k) {
                dataBase[ind].lastOperation[4 - k] = dataBase[ind].lastOperation[3 - k];
            }
            dataBase[ind].lastOperation[0] = last;
            mt.lock();
            foutLog << "ID: " << dataBase[ind].id << ": погашение кредита на " << last << " RUB" << endl;
            printToData();
            mt.unlock();
        }
        else if (req[0] == 'r') {
            while (req[1 + i] != '/')
                temp[i] = req[1 + i++];
            temp[i++] = '\0';
            ++i;
            num = atoi(temp);
            int g = -1;
            for (int k = 0; k < 10; ++k) {
                if (dataBase[k].id == num && k != ind) {
                    g = k;
                    break;
                }
            }
            if (g == -1) {
                mt.lock();
                foutLog << "ID: " << dataBase[ind].id << ": попытка перевода: неверное ID" << endl;
                mt.unlock();
                send(Connections[x], err0, sizeof(err0), NULL);
                continue;
            }
            else {
                send(Connections[x], sLogin, sizeof(sLogin), NULL);
            }
            while (req[i + j] != '\0')
                temp[j] = req[i + j++];
            temp[j] = '\0';
            num = atoi(temp);
            dataBase[ind].balance = dataBase[ind].balance - num;
            dataBase[g].balance += num;
            for (int k = 0; k < 4; ++k) {
                dataBase[ind].lastOperation[4 - k] = dataBase[ind].lastOperation[3 - k];
                dataBase[g].lastOperation[4 - k] = dataBase[g].lastOperation[3 - k];
            }
            dataBase[ind].lastOperation[0] = -num;
            dataBase[g].lastOperation[0] = num;
            mt.lock();
            foutLog << "ID: " << dataBase[ind].id << ": перевод на ID: "<< dataBase[g].id << "  " << num << " RUB" << endl;
            printToData();
            mt.unlock();
        }
        else if (req[0] == 't'){
        itoa(dataBase[ind].balance, temp, 10);
        while (temp[i] != '\0')
            req[i] = temp[i++];
        itoa(dataBase[ind].deposit, temp, 10);
        req[i++] = '/';
        while (temp[j] != '\0')
            req[i+j] = temp[j++];
        req[i + j++] = '/';
        i += j;
        j = 0;
        itoa(dataBase[ind].credit, temp, 10);
        while (temp[j] != '\0')
            req[i + j] = temp[j++];
        req[i + j++] = '/';
        i += j;
        j = 0;
        for (int k = 0; k < 5; ++k) {
            itoa(dataBase[ind].lastOperation[k], temp, 10);
            while (temp[j] != '\0')
                req[i + j] = temp[j++];
            req[i + j++] = '/';
            i += j;
            j = 0;
        }
        req[i + j] = '\0';
        send(Connections[x], req, sizeof(req), NULL);
        continue;
        }
        else if (req[0] == 'y') {
        if (ind == -1) {
            mt.lock();
            foutLog << "Клиент отключился " << endl;
            mt.unlock();
        }
        else {
            mt.lock();
            foutLog << "ID: " << dataBase[ind].id << ": клиент отключился " << endl;
            mt.unlock();
        }
        break;
        }
    }
}

int main()
{
    string str;
    ifstream fin("database.txt");
    ifstream finLog("EventLog.txt");
    ofstream foutLog1("EventLog1.txt");
    for (int i = 0; i < 2; ++i) {
        fin >> dataBase[i].id;
        fin >> dataBase[i].pasword;
        fin >> dataBase[i].balance;
        fin >> dataBase[i].deposit;
        fin >> dataBase[i].credit;
        for(int j = 0; j < 5; ++j)
            fin >> dataBase[i].lastOperation[j];
    }
    while (getline(finLog, str)) {
        foutLog1 << str << endl;
    }
    fin.close();
    foutLog1.close();
    finLog.close();
    //ofstream fout;
    //fout.open("test.txt", std::ofstream::out | std::ofstream::trunc);
    ofstream foutLog("EventLog.txt");
    sort(dataBase,dataBase+2, cmp);
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
    for (int i = 0; i < 100; ++i) {
        if (!(newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr))) { //Извлечение запроса на подключение сокета
            cout << "ERROR";
        }
        else {
            cout << "Client Connected" << endl;
            Connections[i] = newConnection;
            ++counter;
            //CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i, fout), NULL, NULL);
            thread t(ClientHandler, i, ref(foutLog));
            t.detach();
        }
    }

    cout << "Last Error " << WSAGetLastError();
    for (int i = 0; i < counter; ++i) {
        closesocket(Connections[i]); // Закрытие созданного сокета
    }
    WSACleanup(); // Деиницилизация библиотеки Winsock
    //system("pause");
    return 0;
}