#include<cstring>
#include <iostream>
#include<fstream>
using namespace std;

enum syntax_st { S0, U, L, C0, L2, C2, Os, Le, A, A1, A2, A3, Is, E, Bs,Lm,C2m,Ams };
enum state {aom, ao, co, Do, eq, id, lo, lp, no, sc, un, vl, wl, S, I, C, O,Om, Sr, Srm, Tz, R, B };   //Состояния
enum signal { l, D, m, b,Am, Ao, r, tz, rz, el };               //Сигналы
enum state table[23][10] = {
	// l  D  m  b Am ao  r  tz  rz  el
	   S, S, S, S, S, S,  S, S,  S,  S,//aom
	   S, S, S, S, S, S,  S, S,  S,  S, //ao         //Матрица для лексического анализа
	   S, S, S, S, S, S,  S, S,  S,  S, //co
	   S, S, S, S, S, S,  S, S,  S,  S, //Do
	   S, S, S, S, S, S,  S, S,  S,  S,//eq
	   S, S, S, S, S, S,  S, S,  S,  S, //id
	   S, S, S, S, S, S,  S, S,  S,  S, //lo
	   S, S, S, S, S, S,  S, S,  S,  S, //lp
	   S, S, S, S, S, S,  S, S,  S,  S, //no
	   S, S, S, S, S, S,  S, S,  S,  S, //sc
	   S, S, S, S, S, S,  S, S,  S,  S, //un
	   S, S, S, S, S, S,  S, S,  S,  S, //vl
	   S, S, S, S, S, S,  S, S,  S,  S, //wl
	   I, C,Srm,Sr,Om,O, R,  Tz, S,  B,//S
	   I, I, id,id,id,id,id, id,id, B,//I
	   B,C, vl,vl,vl,vl, vl, vl, vl, B,//C
	   ao,ao,ao,ao,ao,ao,ao,ao,ao,ao, //O
	   aom,aom,aom,aom,aom,aom,aom,aom,aom,aom, //O
	   co,co,co,co,co,co,co,co,co,co,//Sr
	   co,co,co,Sr,co,co,co,co,co,co,//Srm
	   sc,sc,sc,sc,sc,sc,sc,sc,sc,sc,//Tz
	   eq,eq,eq,eq,eq,eq,eq,eq,eq,eq,//R
	   B,B,wl,wl,wl,wl,wl,wl,wl,B,//B
};
enum syntax_st table2[18][13]
{
	//aom ao co Do eq id lo lp no sc un vl wl
	  Bs,Bs,Bs,U,Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,//S0
	  Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,L,Bs,Bs,//U    //Матрица для синтаксического анализа
	  Lm,Bs,Bs,Bs,Bs,C0,Bs,Bs,L2,Bs,Bs,C0,Bs,//L
	  Bs,Bs,C2,Bs,C2,Os,L2,Bs,Bs,Bs,Bs,Bs,Bs,//C0
	  Lm,Bs,Bs,Bs,Bs,C0,Bs,Bs,Bs,Bs,Bs,C0,Bs,//L2
	  C2m,Bs,Bs,Bs,Bs,Le,Bs,Bs,Bs,Bs,Bs,Le,Bs,//C2
	  Bs,Bs,Bs,Bs,A,Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,//Os
	  Bs,Bs,Bs,Bs,Bs,Os,L2,Bs,Bs,Bs,Bs,Bs,Bs,//Le
	  Ams,Bs,Bs,Bs,Bs,A1,Bs,Bs,Bs,Bs,Bs,A1,Bs,//A
	  A2,A2,Bs,Bs,Bs,Bs,Bs,E,Bs,Is,Bs,Bs,Bs,//A1
	  Bs,Bs,Bs,Bs,Bs,A3,Bs,Bs,Bs,Bs,Bs,A3,Bs,//A2
	  A2,A2,Bs,Bs,Bs,Bs,Bs,E,Bs,Is,Bs,Bs,Bs,//A3
	  Bs,Bs,Bs,Bs,Bs,Os,Bs,Bs,Bs,Bs,Bs,Bs,Bs,//Is
	  Bs,Bs,Bs,U,Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,//E
	  Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,Bs,//Bs
	  Bs,Bs,Bs,Bs,Bs,C0,Bs,Bs,Bs,Bs,Bs,C0,Bs,//Lm
	  Bs,Bs,Bs,Bs,Bs,Le,Bs,Bs,Bs,Bs,Bs,Le,Bs,//C2m
	  Bs,Bs,Bs,Bs,Bs,A1,Bs,Bs,Bs,Bs,Bs,A1,Bs//Ams

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
		return l;
	if (a == '<')
		return m;
	if (a == '>')
		return b;
	if (a == '=')
		return r;
	if (a == ';')
		return tz;
	if (a == '+' || a == '*' || a == '/')
		return Ao;
	if (a == '-')
		return Am;
	return el;
}
void pushback(lex* head, lex* x)    //Добавление лексемы в список
{
	if (!head->next)
	{
		head->next = x;
		return;
	}
	while (head->next)
		head = head->next;
	head->next = x;
	return;
}
void erase(lex* head)          //Удаление списка
{
	if (head->next)
		erase(head->next);
	delete[] head->word;
	delete head;
}
int check(char* arr)      //Проверка слова на принадлежность к ключевым словам
{
	const int A[6] = { 3,6,6,7,8,10 };
	const char* words[6]{ "do","and","or","loop","not","until" };
	for (int i = 0; i < 6; ++i)
	{                                  //Если слово является ключевым, 
		if (!(strcmp(words[i], arr)))  //то возвращается номер состояния этого слова
			return A[i];
	}
	return 5;
}
void lexanalysis(lex* head, char* arr)
{
	int firstpos = 0;
	int pos = 0;
	int j = 1;
	state st = S;
	lex* temp = head;
	while (pos == 0 || arr[pos - 1] != '\0')
	{
		st = table[st][getsignal(arr[pos])];     //Изменение текущего состояния
		if (st == S)
		{
			firstpos = pos + 1;                //Перенос позиции
			j = 0;
		}
		if (st == ao || st == co || st == eq || st == id || st == sc || st == vl || st == wl|| st == aom)
		{
			lex* Lex = new lex;                     //Запись слова в список лексем
			int size = pos - firstpos;
			Lex->word = new char[size + 1];
			for (int i = 0; i < size; ++i)
				Lex->word[i] = arr[firstpos + i];
			Lex->word[size] = '\0';
			if (st == id)
				Lex->type = (state)(check(Lex->word));
			else
				Lex->type = st;
			Lex->next = 0;
			pushback(temp, Lex);
			temp = temp->next;
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
void output2(int a, syntax_st st, ostream& fout);
void syntax(lex* head, ostream& fout)
{
	lex* temp = head;
	int i = 0;
	syntax_st st = S0;
	syntax_st st0 = S0;
	while (head->next)
	{
		if ((st == Lm || st == C2m || st == Ams) && head->next->type == vl)
		{
			head->type = S;
			--i;
		}
		st0 = st;
		st = table2[st][head->next->type];  //Изменение текущего состояния
		head = head->next;                  //Переход к следующей лексеме
		if (st == Bs)                       //Если плохое состояние, 
		{                                   //то выход из цикла
			break;
		}
		++i;
	}
	output1(temp, fout);
	if (st == Bs)
	{
		output2(i, st0, fout);   
		return;
	}
	if (st != E)               //Если не попало в плохое состояние,
		output2(i, st, fout);  //но не наступило завершение конструкции
	else
		fout << "OK";        //Если конструкция или несколько кострукций полностью верны
}
void output1(lex* head, ostream& fout)    //Вывод
{
	while (head->next)
	{
		fout << head->next->word;
		const char* words[13]{ "[ao]","[ao]","[co]","[do]","[eq]","[id]","[lo]","[lp]","[no]","[sc]","[un]","[vl]","[wl]" };
		if(head->next->type!=S)
			fout << words[head->next->type] << ' ';
		head = head->next;
	}
	fout << endl;
}
void output2(int a, syntax_st st, ostream& fout)    //Вывод
{
	fout << a;
	const char* words[13]{ "ao","ao","co","do","eq","id","lo","lp","no","sc","un","vl","wl" };
	for (int i = 1; i < 13; ++i)
	{
		if (table2[st][i] != Bs)
			fout << ' ' << words[i];
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
		lexanalysis(Lex, arr); //Лексический анализ
		syntax(Lex, fout);     //Синтаксический анализ
		delete[] arr;     //Освобождение памяти
		erase(Lex);        //Освобождение памяти
		fin.close();      //Закрытие файлов
		fout.close();
	}
	return 0;
}
