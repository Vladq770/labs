#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cstdlib>

using namespace std;


int function1(int* arr, int n) {
    int res;
    __asm {
        xor edi, edi; ������� �������� ������������� � ������������� ���������
        mov ebx, arr; ��������� �� ������ �������
        mov ecx, n; ������ �������
        jecxz End; ����� �� �����, ���� ������ 0 �������
    begin_loop:
        mov eax, [ebx + ecx * 4 - 4]; � eax ���������� ������� �������
        cmp eax, 0; ������������ � �����
        jg mg; ���� ������ ����
        jl ml; ���� ������ ����
        jmp end_loop; ���� ����� ����
    mg:
        inc edi; ���������� �������� �� 1
        jmp end_loop; ������� � ��������� ��������
    ml:
        dec edi; ���������� �������� �� 1
        jmp end_loop; ������� � ��������� ��������
    end_loop:
        loop begin_loop; ������ ����� �������� �����, ���� ecx > 0
    End:
        mov eax, edi;  ������� ���������� � eax
        mov res, eax;  ������� ���������� � res
    }
    return res;
}

int function2(int* arr, int n) {
    int res;
    __asm {
        xor edi, edi; ������� �������� ������������� � ������������� ���������
        mov ebx, arr; ��������� �� ������ �������
        mov ecx, n; ������ �������
        jecxz End; ����� �� �����, ���� ������ 0 �������
    begin_loop :
        mov eax, [ebx + ecx * 4 - 4]; � eax ���������� ������� �������
        cmp eax, 0; ������������ � �����
        jg mg; ���� ������ ����
        jl ml; ���� ������ ����
        jmp end_loop; ���� ����� ����
    mg:
        inc edi; ���������� �������� �� 1
        jmp end_loop; ������� � ��������� ��������
    ml:
        dec edi; ���������� �������� �� 1
        jmp end_loop; ������� � ��������� ��������
    end_loop:
        dec ecx; ���������� �������� ����� �� 1
        jnz begin_loop; ������ ����� �������� �����, ���� ecx > 0
    End:
        mov eax, edi;  ������� ���������� � eax
        mov res, eax;  ������� ���������� � res
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
        push ax; // ��������� ax � ����
        add ax,bx; // ax = ax+bx
        pop bx; // bx = ������ ax
        cmp ax, 10000 // ���������� ax c 10000
        jg End; // ���� ������ 10000, �� ����� �������
        jmp beginLoop; // ���� �� ������, �� ����� ��������
     End:
        mov F, ax // ���������� ����������
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
        cwd // ��������� ax �� dx:ax
        div cx // ����� ax �� cx
        cmp dx, bx //  ���������� dx(�������) � bx
        jl dxl; // ���� dx ������, �� ����� ��������
        mov bx, dx; // ���� �� ������, �� ���������� ���
    dxl:
        loop beginLoop; // ����� ��������, --cx
    End:
        mov F, bx // ���������� ����������
    }
    return F;
}

short f3(char n) {
    short K;
    __asm {
        movzx ax, n //ax=n movzx ���������� ������ ��� ax � n ������ ��������
        mov bx, ax // bx=n
        mov cx, 2 // cx=2
        inc bx // bx = bx+1 = n + 1
        mul bx // ax = ax*bx=n*(n+1)
        div cx // ax = ax/cx = n*(n+1)/2
        mov K, ax // ���������� ����������
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
        cout << "������� ������ �������: ";
        while (1) {
            cin >> n;
            if (cin.fail() || cin.peek() != '\n' || n < 1) {
                cin.clear();
                cin.ignore(32768, '\n');
                cout << "���������� �����" << endl;
            }
            else {
                break;
            }
        }
        int* arr = new int[n];
        cout << "������� �������� �������: ";
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (cin.fail()) {
                cin.clear();
                cin.ignore(32768, '\n');
                cout << "���������� �����" << endl;
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
        cout << "1. �������� ���������� ������������� � ������������� ��������� ������� �����: " << res1 << endl;
        cout << "2. �������� ���������� ������������� � ������������� ��������� ������� �����: " << res2 << endl;
        cout << "����������?";
        cin >> f;
        if (f != 'y' && f != 'Y')
            break;
    }*/
    cout << "test" << endl;
    cout << f3(10) << endl;
    return 0;
}
