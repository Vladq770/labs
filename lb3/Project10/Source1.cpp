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
        push eax; ��������� � ���� �
        imul	ebx; <edx:eax> = a * b
        jo error_of1; ��������� ����� �� ������� ������� �����
        add eax, 0
        jz error_zf1; ������ ������� �� ����
        push ecx; ���������  � ���� �
        neg ecx; < ecx > = -c
        push eax; ��������� � ���� a* b
        mov eax, ecx;  < eax > = -c
        cdq; ��������� eax �� <edx:eax>
        pop ecx; ��������� �� ����� < ecx > = a * b
        idiv ecx; < eax > = -c / a * b
        jo error_of2; ������ ������� ������
        mov ecx, eax; < ecx > = -c / a * b
        add ecx, 256; < ecx > = -c / a * b + 256
        jz  error_zf2;  ������ ������� �� ����
        jo error_of2; ������ ������������
        push ecx;  ��������� � ���� - c / a * b + 256
        mov eax, [esp + 4]; < eax > = c
        mov ecx, 2; < ecx > = 2
        imul ecx; <edx:eax> = c * 2
        jo error_of3; ��������� ����� �� ������� ������� �����
        imul ebx; <edx:eax> = 2 * c * b
        jo error_of3; ��������� ����� �� ������� ������� �����
        add eax, [esp + 8]; < eax > = 2 * c * b + a
        sub eax, 21; < eax > = 2 * c * b + a - 21
        jo error_of3; ������ ������������
        pop ecx; ��������� �� ����� < ecx > = -c / a * b + 256
        cdq; ��������� eax �� <edx:eax>
        idiv ecx; < eax > = (2 * c * b + a - 2l) / (-c / a * b + 256)
        jo error_of3; ������ ������� ������
        mov res, eax; ��������� �����
        jmp End0; �������� ����������
        error_of1:
        pop eax; ������� �����
        mov F, -2; ���� ������
        jmp End
        error_of2:
        pop eax; ������� �����
        pop eax; ������� �����
        mov F, -2; ���� ������
        jmp End
        error_of3:
        pop eax; ������� �����
        pop eax; ������� �����
        mov F, -2; ���� ������
        jmp End
        error_zf1:
        pop eax; ������� �����
        mov F, -1; ���� ������
        jmp End
        error_zf2:
        pop eax; ������� �����
        pop eax; ������� �����
        mov F, -1; ���� ������
        jmp End
        End0:
        pop eax; ������� �����
        pop eax; ������� �����
        End:
    }
    if (F == -1)
        cout << "������ ������� �� ����" << endl;
    else if (F == -2)
        cout << "������ ������������" << endl;
    else
        cout << "���������: " << res << endl;
    return 0;
}
