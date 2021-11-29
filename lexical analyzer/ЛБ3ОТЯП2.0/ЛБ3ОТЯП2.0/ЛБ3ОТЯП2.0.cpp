#include <iostream>
#include<fstream>
using namespace std;

enum state { S, I, Ib, Ibe, Ie, C, Cb, Cbe, Ce, O, Ob, Obe, Oe, Sr, Srm, Srb, Srbe, Sre, T, Tb, Tbe, Te, R, Rb, Rbe, Re, B, Be };   //Состояния
enum signal { L, D, m, b, ao, aO, r, tz, rz, el };               //Сигналы
enum state table[28][10] = {
	// L  D  m  b  ao  aO  r  tz  rz  el
	   I, C,Srm,Sr,O,  O,  R,  T, S,  B,//S
	   I, I, Ie,Ie,Ie, Ie, Ie, Ie,Ie, Ib,//I
	   Ib,Ib,Ibe,Ibe,Ibe,Ibe,Ibe,Ibe,Ibe,Ib,//Ib
	   S, S, S, S, S, S, S, S, S, S, //Ibe
	   S, S, S, S, S, S, S, S, S, S, //Ie
	   Cb,C, Ce,Ce,Ce, Ce,Ce, Ce, Ce,Cb,//C
	   Cb,Cb,Cbe,Cbe,Cbe,Cbe,Cbe,Cbe,Cbe,Cb,//Cb
	   S, S, S, S, S, S, S, S, S, S, //Cbe
	   S, S, S, S, S, S, S, S, S, S, //Ce
	   Oe,Oe,Oe,Oe,Oe, Oe, Oe,Oe, Oe, Oe,//O
	   Obe,Obe,Obe,Obe,Ob,Ob,Obe,Obe,Obe,Ob,//Ob
	   S, S, S, S, S, S, S, S, S, S, //Obe
	   S, S, S, S, S, S, S, S, S, S, //Oe
	   Sre,Sre,Sre,Sre,Sre,Sre,Sre,Sre,Sre,Sre,//Sr
	   Sre,Sre,Sre,Sr,Sre,Sre,Sre,Sre,Sre,Sre,//Srm
	   Srbe,Srbe,Srb,Srb,Srbe,Srbe,Srbe,Srbe,Srbe,Srbe,//Srb
	   S, S, S, S, S, S, S, S, S, S, //Srbe
	   S, S, S, S, S, S, S, S, S, S, //Sre
	   Te,Te,Te,Te,Te,Te,Te,Te,Te,Te,//T
	   Tbe,Tbe,Tbe,Tbe,Tbe,Tbe,Tbe,Tb,Tbe,Tbe,//Tb
	   S, S, S, S, S, S, S, S, S, S, //Tbe
	   S, S, S, S, S, S, S, S, S, S, //Te
	   Re,Re,Re,Re,Re,Re,Re,Re,Re,Re,//R
	   Rbe,Rbe,Rb,Rb,Rb,Rb,Rb,Rbe,Rbe,Rbe,//Rb
	   S, S, S, S, S, S, S, S, S, S, //Rbe
	   S, S, S, S, S, S, S, S, S, S, //Re
	   B,B,Be,Be,Be,Be,Be,Be,Be,B,//B
	   S, S, S, S, S, S, S, S, S, S//Be

};
struct lex             //Объявление структуры лексем
{
	char* word;
	state type;
	lex* next;
};
signal getsignal(char a)        //Функция, распознающая сигнал
{
	if (a == '\n' || a == ' ' || a == '\t' || a == '\r' || a == '\0')
		return rz;
	if (isdigit((int)a))
		return D;
	if (isalpha((int)a))
		return L;
	if (a == '<')
		return m;
	if (a == '>')
		return b;
	if (a == '=')
		return r;
	if (a == ';')
		return tz;
	if (a == '+' || a == '*' || a == '/')
		return ao;
	if (a == '-')
		return aO;
	return el;
}
void pushback(lex* head, lex* x)    //Добавление лексемы в список
{
	lex* T = head;
	if (head->next) {
		T = head->next;
		while (T->next)
			T = T->next;
		T->next = x;
		x->next = 0;
	}
	else {
		head->next = x;
		x->next = 0;
	}
}
void erase(lex* head)          //Удаление списка
{
	if (head->next)
		erase(head->next);
	delete[] head->word;
	delete head;
}
bool check(char* arr)      //Проверка слова на принадлежность к ключевым словам
{
	const char d[2] = { 'd','o' };
	const char u[5] = { 'u','n','t','i','l' };
	const char l[4] = { 'l','o','o','p' };
	const char n[3] = { 'n','o','t' };
	const char a[3] = { 'a','n','d' };
	const char o[2] = { 'o','r' };
	int i = 0;
	while (arr[i] != '\0' && i < 2)
	{
		if (arr[i] != d[i])
			break;
		if (i == 1 && arr[i + 1] == '\0')
			return 1;
		++i;
	}
	i = 0;
	while (arr[i] != '\0' && i < 5)
	{
		if (arr[i] != u[i])
			break;
		if (i == 4 && arr[i + 1] == '\0')
			return 1;
		++i;
	}
	i = 0;
	while (arr[i] != '\0' && i < 4)
	{
		if (arr[i] != l[i])
			break;
		if (i == 3 && arr[i + 1] == '\0')
			return 1;
		++i;
	}
	i = 0;
	while (arr[i] != '\0' && i < 3)
	{
		if (arr[i] != n[i])
			break;
		if (i == 2 && arr[i + 1] == '\0')
			return 1;
		++i;
	}
	i = 0;
	while (arr[i] != '\0' && i < 3)
	{
		if (arr[i] != a[i])
			break;
		if (i == 2 && arr[i + 1] == '\0')
			return 1;
		++i;
	}
	i = 0;
	while (arr[i] != '\0' && i < 2)
	{
		if (arr[i] != o[i])
			break;
		if (i == 1 && arr[i + 1] == '\0')
			return 1;
		++i;
	}
	return 0;
}
void lexanalysis(lex* head, char* arr)
{
	int firstpos = 0;
	int pos = 0;
	int j = 1;
	state st = S;
	while (pos == 0 || arr[pos - 1] != '\0')
	{
		st = table[st][getsignal(arr[pos])];     //Изменение текущего состояния
		if (st == S)
		{
			firstpos = pos + 1;                //Перенос позиции
			j = 0;
		}
		if (st == Ie || st == Ce || st == Oe || st == Sre || st == Re || st == Te)
		{
			lex* Lex = new lex;                     //Запись слова в список лексем
			int size = pos - firstpos;
			Lex->word = new char[size + 1];
			for (int i = 0; i < size; ++i)
				Lex->word[i] = arr[firstpos + i];
			Lex->word[size] = '\0';
			if (st==Ie&&check(Lex->word))
				Lex->type = I;
			else
				Lex->type = st;
			pushback(head, Lex);
			st = S;
			--pos;
			firstpos = pos + 1;
			j = 0;
		}
		if (st == Ibe || st == Cbe || st == Obe || st == Srbe || st == Rbe || st == Tbe || st == Be)
		{
			lex* Lex = new lex;                     //Запись слова в список лексем
			int size = pos - firstpos;
			Lex->word = new char[size + 1];
			for (int i = 0; i < size; ++i)
				Lex->word[i] = arr[firstpos + i];
			Lex->word[size] = '\0';
			Lex->type = S;
			pushback(head, Lex);
			st = S;
			--pos;
			firstpos = pos + 1;
			j = 0;
		}
		if (j == 6)
			st = B;
		++j;
		++pos;       //Переход к следующему символу
	}
}
void output1(lex* head, ostream& fout);
void output2(lex* head, ostream& fout);
void output3(lex* head, ostream& fout);
void output(lex* head, ostream& fout)    //Вывод
{
	if (head->next)
	{
		output1(head, fout);
		output2(head, fout);
		output3(head, fout);
	}
}
void output1(lex* head, ostream& fout)    //Вывод
{
	while (head->next)
	{
		int i = 0;
		head = head->next;
		while (head->word[i] != '\0')
		{
			fout << head->word[i++];
		}
		if (head->type == I)
			fout << "[kw]";
		if (head->type == Ce)
			fout << "[vl]";
		if (head->type == Ie)
			fout << "[id]";
		if (head->type == S)
			fout << "[wl]";
		if (head->type == Sre)
			fout << "[co]";
		if (head->type == Re)
			fout << "[eq]";
		if (head->type == Oe)
			fout << "[ao]";
		if (head->type == Te)
			fout << "[sc]";
		fout << ' ';
		i = 0;
	}
	fout << endl;
}
void output2(lex* head, ostream& fout)    //Вывод
{
	while (head->next)
	{
		head = head->next;
		if (head->type == Ie)
		{
			int i = 0;
			while (head->word[i] != '\0')
			{
				fout << head->word[i++];
			}
			fout << ' ';
		}
	}
	fout << endl;
}
void output3(lex* head, ostream& fout)    //Вывод
{
	while (head->next)
	{
		head = head->next;
		if (head->type == Ce)
		{
			int i = 0;
			while (head->word[i] != '\0')
			{
				fout << head->word[i++];
			}
			fout << ' ';
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("input.txt", ios::binary);
	ofstream fout("output.txt");
	if (fin.is_open()) //Проверка на открытие файла
	{
		int size = 0;
		fin.seekg(0, ios::end);    //Нахождение количества элементов в файле
		size = fin.tellg();
		++size;
		fin.seekg(0, ios::beg);
		lex* Lex = new lex;
		Lex->next = 0;
		Lex->word = new char[1];
		char* arr = new char[size];
		fin.getline(arr, size, '\0');   //Считывание файла
		lexanalysis(Lex, arr);
		delete[] arr;     //Освобождение памяти
		output(Lex, fout);   //Вывод
		erase(Lex);        //Освобождение памяти
		fin.close();      //Закрытие файлов
		fout.close();
	}
	return 0;
}
