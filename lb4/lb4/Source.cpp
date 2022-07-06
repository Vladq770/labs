#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cstdlib>

using namespace std;


int function1(int* arr, int n) {
    int res;
    __asm {
        xor edi, edi; счетчик разности положителньых и отрицательных элементов
        mov ebx, arr; указатель на начало массива
        mov ecx, n; размер массива
        jecxz End; выход из цикла, если массив 0 размера
    begin_loop:
        mov eax, [ebx + ecx * 4 - 4]; в eax помещается элемент массива
        cmp eax, 0; сравнивается с нулем
        jg mg; если больше нуля
        jl ml; если меньше нуля
        jmp end_loop; если равно нулю
    mg:
        inc edi; увеличение счетчика на 1
        jmp end_loop; переход к следующей итерации
    ml:
        dec edi; уменьшение счетчика на 1
        jmp end_loop; переход к следующей итерации
    end_loop:
        loop begin_loop; начало новой итерации цикла, если ecx > 0
    End:
        mov eax, edi;  перенос результата в eax
        mov res, eax;  перенос результата в res
    }
    return res;
}

int function2(int* arr, int n) {
    int res;
    __asm {
        xor edi, edi; счетчик разности положителньых и отрицательных элементов
        mov ebx, arr; указатель на начало массива
        mov ecx, n; размер массива
        jecxz End; выход из цикла, если массив 0 размера
    begin_loop :
        mov eax, [ebx + ecx * 4 - 4]; в eax помещается элемент массива
        cmp eax, 0; сравнивается с нулем
        jg mg; если больше нуля
        jl ml; если меньше нуля
        jmp end_loop; если равно нулю
    mg:
        inc edi; увеличение счетчика на 1
        jmp end_loop; переход к следующей итерации
    ml:
        dec edi; уменьшение счетчика на 1
        jmp end_loop; переход к следующей итерации
    end_loop:
        dec ecx; уменьшение счетчика цикла на 1
        jnz begin_loop; начало новой итерации цикла, если ecx > 0
    End:
        mov eax, edi;  перенос результата в eax
        mov res, eax;  перенос результата в res
    }
    return res;
}
/*char f(short x) {
    char res;
    __asm {
        mov ax, x;
        mov bx, 3;
        xor cl,cl
    beginLoop:
        div bx;
        inc cl;
        cmp dx, 0;
        jnz m;
        beginLoop
    m:
        cmp ax, 1;
        je EndLoop;
        jmp End1;
    EndLoop:
        mov res, cl;
        jmp End;
    End1:
        mov res, -1;
    End:
    }
    return res;
}*/

short f1() {
    short F;
    __asm {
        mov ax,1  //ax=1
        mov bx,1 //bx=1
    beginLoop:
        push ax; // сохраняем ax в стек
        add ax,bx; // ax = ax+bx
        pop bx; // bx = старый ax
        cmp ax, 10000 // сравниваем ax c 10000
        jg End; // если больше 10000, то конец функции
        jmp beginLoop; // если не больше, то новая итерация
     End:
        mov F, ax // сохранение результата
    }
    return F;
}
short f2(short n, short k) {
    short F;
    __asm {
        mov cx, k //cx=k
        mov bx, 0; // bx=0
    beginLoop:
        mov ax, n // ax = n
        cwd // расширяем ax до dx:ax
        div cx // делим ax на cx
        cmp dx, bx //  сравниваем dx(остаток) с bx
        jl dxl; // если dx меньше, то некст итерация
        mov bx, dx; // если не меньше, то запоминаем его
    dxl:
        loop beginLoop; // некст итерация, --cx
    End:
        mov F, bx // сохранение результата
    }
    return F;
}

short f3(char n) {
    short K;
    __asm {
        movzx ax, n //ax=n movzx используем потому что ax и n разных размеров
        mov bx, ax // bx=n
        mov cx, 2 // cx=2
        inc bx // bx = bx+1 = n + 1
        mul bx // ax = ax*bx=n*(n+1)
        div cx // ax = ax/cx = n*(n+1)/2
        mov K, ax // сохранение результата
    }
    return K;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    char F;
    /*while (1) {
        int n;
        int res1, res2;
        cout << "Введите размер массива: ";
        while (1) {
            cin >> n;
            if (cin.fail() || cin.peek() != '\n' || n < 1) {
                cin.clear();
                cin.ignore(32768, '\n');
                cout << "Попробуйте снова" << endl;
            }
            else {
                break;
            }
        }
        int* arr = new int[n];
        cout << "Введите элементы массива: ";
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (cin.fail()) {
                cin.clear();
                cin.ignore(32768, '\n');
                cout << "Попробуйте снова" << endl;
                --i;
            }
        }
        cout << "arr: ";
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << "  ";
        }
        cout << endl;
        res1 = function1(arr, n);
        res2 = function2(arr, n);
        delete[] arr;
        cout << "1. Разность количества положительных и отрицательных элементов массива равна: " << res1 << endl;
        cout << "2. Разность количества положительных и отрицательных элементов массива равна: " << res2 << endl;
        cout << "Продолжить?";
        cin >> f;
        if (f != 'y' && f != 'Y')
            break;
    }*/
    cout << "test" << endl;
    cout << f3(10) << endl;
    return 0;
}
