#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cstdlib>

using namespace std;
int F = 0;
double getFunctionValue(double a, double b, double c) {
    double res = 0;
    const double c1 = -1;
    const double c2 = 2;
    const double c21 = -21;
    const double c256 = 256;
    __asm {
        finit; инициализация сопроцессора
        fld qword ptr[c]; st[0] = c
        fmul qword ptr[c2]; st[0] = 2*c
        fmul qword ptr[b]; st[0] = 2*c*b
        fadd qword ptr[a]; st[0] = 2*c*b + a
        fadd qword ptr[c21]; st[0] = 2*c*b + a - 21
        fld qword ptr[c]; st[0] = c, st[1] = 2 * c * b + a - 21
        fld qword ptr[a]; st[0] = a, st[1] = c, st[2] = 2 * c * b + a - 21
        fmul qword ptr[b]; st[0] = a*b, st[1] = c, st[2] = 2 * c * b + a - 21
        fldz; st[0] = 0, st[1] = a * b, st[2] = c, st[3] = 2 * c * b + a - 21
        fucompp; st[0] = c, st[1] = 2 * c * b + a - 21
        fnstsw ax; записываем значения SWR в AX
        sahf; записываем содержимое AH в младший байт EFLAGS
        jz error_z; проверка на ноль
        fdiv qword ptr[a]; st[0] = c/a, st[1] = 2 * c * b + a - 21
        fdiv qword ptr[b]; st[0] = c /(a*b), st[1] = 2 * c * b + a - 21
        fmul qword ptr[c1]; st[0] = -c/(a*b), st[1] = 2 * c * b + a - 21
        fadd qword ptr[c256]; st[0] = -c/(a * b) + 256, st[1] = 2 * c * b + a - 21
        fldz; st[0] = 0, st[1] = -c / (a * b) + 256, st[2] = 2 * c * b + a - 21
        fucomp; st[0] = -c / (a * b) + 256, st[1] = 2 * c * b + a - 21
        fnstsw ax;  записываем значения SWR в AX
        sahf;  записываем содержимое AH в младший байт EFLAGS
        jz error_z;  проверка на ноль
        fdivp st(1), st; st[0] = (2 * c * b + a - 2l) / (-c / a * b + 256)
        fstp res; res = st[0], стек пуст
        jmp End;
    error_z:
        mov F, 1; флаг деления на ноль
    End:
    }
    //(2*c*b + a - 2l)/(-c/a*b+256);   
    return res;
}
double check(double a, double b, double c) {
    //(2*c*b + a - 2l)/(-c/a*b+256);   
    return (2 * c * b + a - 21) / (-c / (a * b) + 256);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    char f;
    double a, b, c;
    double res1, res2;
    while (1) {
        cout << "Введите a  ";
        while (1) {
            cin >> a;
            if (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(32768, '\n');
                cout << "Попробуйте снова" << endl;
            }
            else {
                break;
            }
        }
        cout << "Введите b  ";
        while (1) {
            cin >> b;
            if (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(32768, '\n');
                cout << "Попробуйте снова" << endl;
            }
            else {
                break;
            }
        }
        cout << "Введите c  ";
        while (1) {
            cin >> c;
            if (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(32768, '\n');
                cout << "Попробуйте снова" << endl;
            }
            else {
                break;
            }
        }
        res1 = getFunctionValue(a, b, c);
        res2 = check(a, b, c);
        if (!F) {
            cout << "Результат ассемблера: " << res1 << endl;
            cout << "Результат С++: " << res2 << endl;
        }
        else {
            cout << "Ошибка деления на ноль" << endl;
            F = 0;
        }
        cout << "Продолжить?";
        cin >> f;
        if (f != 'y' && f != 'Y')
            break;
    }
    return 0;
}
