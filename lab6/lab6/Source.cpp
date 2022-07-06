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
        finit; ������������� ������������
        fld qword ptr[b]; st0 = b
        fld qword ptr[a]; st0 = a, st1 = b
        fcom st(1); ���������� a � b
        fstsw status; ��������� ������� ��������� ������������
        mov ah, byte ptr[status + 1]; ��������� � ah ������ ���� �� status
        sahf;  ���������� ���������� ah � ������� FLAGS
        ja a_bigger;  ���� a>b
        jb b_bigger;  ���� a<b
        fld c111;     st0 = 111, st1 = a, st2 = b
        jmp endcalc;  ������� � ���������� �������
    a_bigger:
        ftst;   ��������� � � 0
        fnstsw ax; ��������� ������� ������ ������������
        sahf;    ���������� � ������� ������ ����������
        jz error_z;  �������, ���� � = 0
        fdivp st(1), st;  st0 = b/a
        fld1; st0 = 1, st1 = b/a
        fadd; st0 = b/a + 1, st1 = b/a
        jmp endcalc;  ������� � ���������� �������
    b_bigger:
        fldz;  st0 = 0, st1 = a, st2 = b
        fcomp st(2); ��������� b � 0, st0 = a, st1 = b
        fnstsw ax;  ��������� ������� ������ ������������
        sahf;   ���������� � ������� ������ ����������
        jz error_z; �������, ���� b = 0
        fld c11; st0 = -11, st1 = a, st2 = b
        faddp st(1), st; st0 = a-11, st1 = b
        fld qword ptr[b]; st0 = b, st1 = a-11, st2 = b
        fdivp st(1), st; st0 =(a-11)/b, st1 = b
        jmp endcalc;  ������� � ���������� �������
    error_z:
        mov F, 1; ���� ������� �� ����
        jmp End; ����������
    endcalc:
        fxam; ������ ����������
        fstsw ax;  ��������� ������� ������ ������������
        sahf;   ���������� � ������� ������ ����������
        jc not_Number;
        fstp res; res = st0
        jmp End;
    not_Number:
        mov F, 2; ���� NaN
        jmp End; ����������
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
        cout << "������� a  ";
        while (1) {
            cin >> a;
            if (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(32768, '\n');
                cout << "���������� �����" << endl;
            }
            else {
                break;
            }
        }
        cout << "������� b  ";
        while (1) {
            cin >> b;
            if (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(32768, '\n');
                cout << "���������� �����" << endl;
            }
            else {
                break;
            }
        }
        res1 = getFunctionValue(a, b);
        res2 = check(a, b);
        if (!F) {
            cout << "��������� ����������: " << res1 << endl;
            cout << "��������� �++: " << res2 << endl;
        }
        else {
            cout << "������ ������� �� ����" << endl;
            F = 0;
        }
        cout << "����������?";
        cin >> f;
        if (f != 'y' && f != 'Y')
            break;
    }
    return 0;
}
