#include <iostream>
#include<fstream>
using namespace std;

struct list       //Объявление структуры
{
	int val;  
	list* next;
};
list* index(list* head, int i)   //Функция индексирования
{
	if (i == -1)
		return head;
	list* temp = head->next;
	while (i--)
		temp = temp->next;
	return temp;
}
void pushback(list* head, int a)        //Функция вставки элемента в конец списка
{
	list* T = head;
	if (head->next) {          //Если список не пуст
		T = head->next;
		while (T->next != head->next)
			T = T->next;
		list* last = new list;
		last->val = a;
		last->next = head->next;
		T->next = last;
	}
	else {             //Если список пуст
		list* last = new list;
		last->val = a;
		last->next = last;
		head->next = last;
	}
}
void pswap(list*& a, list*& b, list* head)     //Функция свапа для пузырька
{
	if (a == head)
	{ 
		list* last = head->next;
		while(last->next!=head->next)
			last=last->next;
		list* x = b->next->next;
		list* y = b;
		head->next = b->next;
		b->next = y;
		b->next->next = x;
		last->next = head->next;
		return;
	}
	list* x = b->next->next;
	list* y = b;
	b = b->next;
	b->next=y;
	b->next->next = x;
}
bool notsort(list* head)     //Проверка списка на отсортированность
{
	list* j = head->next;
	while (j->next != head->next)
	{
		if (j->val > j->next->val)
			return 1;
		j = j->next;
	}
	return 0;
}
void Bsort(list* head)       //Сортировка пузырьком
{

	list* i = head;
	while (notsort(head))    //Пока не отсортировано
	{
		while (i->next->next != head->next)
		{
			
			if (i->next->val > i->next->next->val)
			{
				pswap(i, i->next, head);
			}
			i = i->next;
		}
		i = head;
	}
}
void qqsort(list* &head,int first, int last)
{
	int i = first;
	int j = last - 1;
	int mid = index(head, (first + last) / 2)->val;
	do {
		while (index(head, i)->val < mid)   //Поиск элемента большего центрального
		{
			i++;
		}
		while (index(head, j)->val > mid)   //Поиск элемента меньшего центрального
		{
			j--;
		}
		if (i <= j)
		{
			list* beg = (index(head, i));
			list* end = (index(head, j));
			swap(beg->val,end->val);   //Смена элементов местами

			i++;
			j--;
		}
	} while (i <= j);
	if (j > first)           //Рекурсивный запуск функции сортировки
	{
		qqsort(head,first, j + 1);
	}
	if (i < last)
	{
		qqsort(head,i, last);
	}
}
void erase(list* head)           //Функция очистки памяти
{
	list* x = head->next;
	list* y = head;
	list* Y;
	while (x->next != head->next)
	{
		x = x->next;
	}
	while (y->next != x)
	{
		Y = y;
		y = y->next;
		delete Y;
	}
	delete y->next;
	delete y;
}
void output(list* head,ofstream& fout)      //Функция вывода
{
	list* Q1 = head->next;
	do
	{
		fout << Q1->val << ' ';
		Q1 = Q1->next;
	} while (Q1 != head->next);
}
int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	if (fin.is_open())             //Проверка на отрытие файла
	{
		int x;
		fin >> x;
		list* Q = new list;       //Объявление списка
		Q->next = 0;
		int a;
		int k = 0;
		while (fin >> a)          //Заполнение списка
		{
			++k;
			pushback(Q, a);
		}
		fout << k << ' ';
		if (x == 0)
			qqsort(Q, 0, k);
		else
			Bsort(Q);
		output(Q,fout);
		erase(Q);
		fout.close();    //Закрытие файлов
		fin.close();
	}
	return 0;
}
