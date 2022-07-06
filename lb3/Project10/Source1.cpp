#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int  a, b, c;
    int F = 0;
    int res;
    cin >> a >> b >> c;
    //(2*c*b + a - 2l)/(-c/a*b+256);    
    __asm {

        mov	eax, a; < eax > = a
        mov	ebx, b; < ebx > = b
        mov	ecx, c; < ecx > = c
        push eax; сохраняем в стек а
        imul	ebx; <edx:eax> = a * b
        jo error_of1; результат вышел за пределы младшей части
        add eax, 0
        jz error_zf1; ошибка деление на ноль
        push ecx; сохраняем  в стек с
        neg ecx; < ecx > = -c
        push eax; сохраняем в стек a* b
        mov eax, ecx;  < eax > = -c
        cdq; расширяем eax до <edx:eax>
        pop ecx; извлекаем из стека < ecx > = a * b
        idiv ecx; < eax > = -c / a * b
        jo error_of2; ошибка частное велико
        mov ecx, eax; < ecx > = -c / a * b
        add ecx, 256; < ecx > = -c / a * b + 256
        jz  error_zf2;  ошибка деление на ноль
        jo error_of2; ошибка переполнения
        push ecx;  сохраняем в стек - c / a * b + 256
        mov eax, [esp + 4]; < eax > = c
        mov ecx, 2; < ecx > = 2
        imul ecx; <edx:eax> = c * 2
        jo error_of3; результат вышел за пределы младшей части
        imul ebx; <edx:eax> = 2 * c * b
        jo error_of3; результат вышел за пределы младшей части
        add eax, [esp + 8]; < eax > = 2 * c * b + a
        sub eax, 21; < eax > = 2 * c * b + a - 21
        jo error_of3; ошибка переполнения
        pop ecx; извлекаем из стека < ecx > = -c / a * b + 256
        cdq; расширяем eax до <edx:eax>
        idiv ecx; < eax > = (2 * c * b + a - 2l) / (-c / a * b + 256)
        jo error_of3; ошибка частное велико
        mov res, eax; сохраняем ответ
        jmp End0; успешное завершение
        error_of1:
        pop eax; очистка стека
        mov F, -2; флаг ошибки
        jmp End
        error_of2:
        pop eax; очистка стека
        pop eax; очистка стека
        mov F, -2; флаг ошибки
        jmp End
        error_of3:
        pop eax; очистка стека
        pop eax; очистка стека
        mov F, -2; флаг ошибки
        jmp End
        error_zf1:
        pop eax; очистка стека
        mov F, -1; флаг ошибки
        jmp End
        error_zf2:
        pop eax; очистка стека
        pop eax; очистка стека
        mov F, -1; флаг ошибки
        jmp End
        End0:
        pop eax; очистка стека
        pop eax; очистка стека
        End:
    }
    if (F == -1)
        cout << "Ошибка деление на ноль" << endl;
    else if (F == -2)
        cout << "Ошибка переполнения" << endl;
    else
        cout << "Результат: " << res << endl;
    return 0;
}
