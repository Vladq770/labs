#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#include "MyForm.h"
#include "MyForm1.h"
#include "MyForm2.h"
#include <winsock2.h>
#include <Windows.h>
#include <iostream>
#include <fstream>

using namespace OS6; // Название проекта

SOCKET Connect;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    WSAData wsaData;  //создаем структуру для загрузки
    WORD DLLVersion = MAKEWORD(2, 1);  //Запрос версии winsock
    if (WSAStartup(DLLVersion, &wsaData)) {  //Загрузка библиотеки
        exit(1);
    }
    int x = WSAGetLastError();
    
    SOCKADDR_IN addr; // структура для описания сокета
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //адрес
    addr.sin_port = htons(1111); //порт
    addr.sin_family = AF_INET; //семейство протоколов
    char t[123] = "TEST";
    Connect = socket(AF_INET, SOCK_STREAM, NULL);
     x = Connect;
    connect(Connect, (SOCKADDR*)&addr, sizeofaddr);
    x = Connect;
    x = GetLastError();
    //send(Connect, t, sizeof(t), NULL);
    x = GetLastError();
    Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
    closesocket(Connect);
    WSACleanup(); // Деиницилизация библиотеки Winsock
	return 0;
}