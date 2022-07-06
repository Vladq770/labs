#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cstdlib>

using namespace std;
int F = 0;
double getFunctionValue(double a, double b) {
    //        b/a + 1     a > b
    //  X =   111         a == b
    //        (a-11)/b    a < b
    double res = 0;
    int status;
    const double c11 = -11;
    const double c111 = 111;
    __asm {
        finit; инициализация сопроцессора
        fld qword ptr[b]; st0 = b
        fld qword ptr[a]; st0 = a, st1 = b
        fcom st(1); сравниваем a и b
        fstsw status; сохраняем регистр состояний сопроцессора
        mov ah, byte ptr[status + 1]; сохраняем в ah второй байт от status
        sahf;  записываем содержимое ah в регистр FLAGS
        ja a_bigger;  если a>b
        jb b_bigger;  если a<b
        fld c111;     st0 = 111, st1 = a, st2 = b
        jmp endcalc;  переход к завершению функции
    a_bigger:
        ftst;   сравнение а с 0
        fnstsw ax; сохраняем регистр флагов сопроцессора
        sahf;    записываем в регистр флагов процессора
        jz error_z;  переход, если а = 0
        fdivp st(1), st;  st0 = b/a
        fld1; st0 = 1, st1 = b/a
        fadd; st0 = b/a + 1, st1 = b/a
        jmp endcalc;  переход к завершению функции
    b_bigger:
        fldz;  st0 = 0, st1 = a, st2 = b
        fcomp st(2); сравнение b с 0, st0 = a, st1 = b
        fnstsw ax;  сохраняем регистр флагов сопроцессора
        sahf;   записываем в регистр флагов процессора
        jz error_z; переход, если b = 0
        fld c11; st0 = -11, st1 = a, st2 = b
        faddp st(1), st; st0 = a-11, st1 = b
        fld qword ptr[b]; st0 = b, st1 = a-11, st2 = b
        fdivp st(1), st; st0 =(a-11)/b, st1 = b
        jmp endcalc;  переход к завершению функции
    error_z:
        mov F, 1; флаг деления на ноль
        jmp End; завершение
    endcalc:
        fxam; анализ результата
        fstsw ax;  сохраняем регистр флагов сопроцессора
        sahf;   записываем в регистр флагов процессора
        jc not_Number;
        fstp res; res = st0
        jmp End;
    not_Number:
        mov F, 2; флаг NaN
        jmp End; завершение
    End:
    }
    //        b/a + 1     a > b
    //  X =   111         a == b
    //        (a-11)/b    a < b
    return res;
}
double check(double a, double b) {
    if (a > b)
        return (b / a) + 1;
    else if (a == b)
        return 111;
    return (a - 11) / b;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    char f;
    double a, b;
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
        res1 = getFunctionValue(a, b);
        res2 = check(a, b);
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
