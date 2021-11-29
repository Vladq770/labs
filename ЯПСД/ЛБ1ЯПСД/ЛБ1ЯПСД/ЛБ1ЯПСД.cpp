#include <iostream>
#include <fstream>
using namespace std;

double sum3(double* arr, int i)           //Функция суммирования кубов положительных чисел массива
{
	double s = 0;
	for (;i--;)
			s += arr[i] * arr[i] * arr[i];
	return s;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	if (fin.is_open())             //Проверка на отрытие файла
	{
		int i = 0;
		int n = 10;
		double* arr = NULL;
		arr = (double*)malloc(n * sizeof(double));
		double b;
		while (fin >> b)                  //Считывание элементов массива
		{
			if (i < n)                    //Если массив еще не заполнен
			{
				if (b > 0)                //В массив записываются только положительные числа
				{
					arr[i++] = b;
				}
			}
			else                        //Если массив заполнен,
			{
				n *= 2;                
				arr = (double*)realloc(arr, n * sizeof(double)); //то количество его элементов увеличивается в 2 раза
				arr[i++] = b;
			}
		}
		fout << sum3(arr, i) << endl;
		free(arr);                   //Удаление массива
	}
	else {} 
	fin.close();         //Закрытие файлов
	fout.close();
	return 0;
}