#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct dot        //Структура точки для класса потомка
{
	double x0;
	double y0;
	double z0;
};
class vector3d          //Базовый класс
{
protected:              //Координаты вектора
	double x;
	double y;
	double z;
public:
	double getx()const      //Методы геттеры
	{
		return x;
	}
	double gety()const
	{
		return y;
	}
	double getz()const
	{
		return z;
	}
	vector3d() :x(0), y(0), z(0) {}; //Конструктор по умолчанию
	vector3d(double x1, double y1, double z1) :x(x1), y(y1), z(z1) {};   //Конструктор инициализации
	vector3d(const vector3d& a) :x(a.x), y(a.y), z(a.z) {};    //Конструктор копирования
	~vector3d() {};     //Деструктор
	double module() const;  //Метод модуля вектора
	double guidecos(int) const;  //Метод направляющих косинусов
	double angleaxis(int) const; //Метод угла с осью
	double angle(const vector3d& T) const;  //Метод угла между векторами
	vector3d& operator = (const vector3d&); //Перегрузка присваивания
	friend vector3d operator+ (const vector3d&,const vector3d&);         //Объявление дружественных функций
	friend vector3d operator- (const vector3d& ,const vector3d&);
	friend vector3d operator* (const vector3d& , const vector3d&);
	friend vector3d operator* (const vector3d& , int );
	friend vector3d operator/ (const vector3d& ,int );
	friend ostream& operator<< (ostream&,vector3d);
	friend istream& operator>> (istream&, vector3d&);
	friend bool operator== (const vector3d&, const vector3d&);
	friend bool operator!= (const vector3d&, const vector3d&);
	friend bool operator< (const vector3d&, const vector3d&);
	friend bool operator<= (const vector3d&, const vector3d&);
	friend bool operator> (const vector3d&, const vector3d&);
	friend bool operator>= (const vector3d&, const vector3d&);
};
double vector3d::module() const
{
	return sqrt(x * x + y * y + z * z);
}
double vector3d::guidecos(int a) const
{
	if (!a)
		return x / module();
	if (a == 1)
		return y / module();
	if (a == 2)
		return z / module();
	return 10;
}
double vector3d::angleaxis(int a) const
{
	if(a==0||a==1||a==2)
		return acos(guidecos(a));
	return 10;
}
double vector3d::angle(const vector3d& T) const
{
	return acos((x * T.x + y * T.y + z * T.z) / (module() * T.module()));
}
vector3d& vector3d:: operator= (const vector3d& T1)
{
	if (this != &T1)
	{
		x = T1.x;
		y = T1.y;
		z = T1.z;
	}
	return *this;
}
vector3d operator+ (const vector3d& T1, const vector3d& T2)
{
	return vector3d(T1.x + T2.x, T1.y + T2.y, T1.z + T2.z);
}
vector3d operator - (const vector3d& T1, const vector3d& T2)
{
	return vector3d(T1.x - T2.x, T1.y - T2.y, T1.z - T2.z);
}
vector3d operator* (const vector3d& T1, const vector3d& T2)
{
	return vector3d(T1.y * T2.z - T1.z * T2.y, T1.z * T2.x - T1.x * T2.z, T1.x * T2.y - T1.y * T2.x);
}
vector3d operator* (const vector3d& T1, int a)
{
	return vector3d(T1.x * a, T1.y * a, T1.z * a);
}
vector3d operator/ (const vector3d& T1,int a)
{
	return vector3d(T1.x / a, T1.y / a, T1.z / a);
}
ostream& operator<< (ostream& fout, vector3d T)
{
	fout << '(' << T.getx() << ", " << T.gety() << ", " << T.getz() << ')';
	return fout;
}
istream& operator>> (istream& fin, vector3d& T)
{
	char c;
	fin >> c;
	fin >> T.x;
	fin >> c;
	fin >> T.y;
	fin >> c;
	fin >> T.z;
	fin >> c;
	return fin;
}
bool operator== (const vector3d& T1, const vector3d& T2)
{
	return(T1.x == T2.x && T1.y == T2.y && T1.z == T2.z);
}
bool operator!= (const vector3d& T1, const vector3d& T2)
{
	return !(T1 == T2);
}
bool operator< (const vector3d& T1, const vector3d& T2)
{
	return(T1.module() < T2.module());
}
bool operator> (const vector3d& T1, const vector3d& T2)
{
	return(T1.module() > T2.module());
}
bool operator<= (const vector3d& T1, const vector3d& T2)
{
	return(T1.module() <= T2.module());
}
bool operator>= (const vector3d& T1, const vector3d& T2)
{
	return(T1.module() >= T2.module());
}
class vector3dV2 :public vector3d    //Производный класс
{
protected:
	dot N;              //Поле точки, от которой отложен вектор
public:
	vector3dV2() : vector3d()   //Конструктор по умолчанию
	{
		N.x0 = 0;
		N.y0 = 0;
		N.z0 = 0;
	};
	vector3dV2(double x1, double y1, double z1) : vector3d(x1,y1,z1)  //Конструктор инициализации без начальной точки
	{
		N.x0 = 0;
		N.y0 = 0;
		N.z0 = 0;
	};
	vector3dV2(double x1, double y1, double z1, double X, double Y, double Z) : vector3d(x1, y1, z1) 
	{                //Конструктор инициализации с начальной точкой
		N.x0 = X;
		N.y0 = Y;
		N.z0 = Z;
	}
	vector3dV2(const vector3dV2& a) : vector3d(a) //Конструктор копирования
	{
		N.x0 = a.N.x0;
		N.y0 = a.N.y0;
		N.z0 = a.N.z0;
	};
	~vector3dV2() {};   //Деструктор
	double scalarproduct(const vector3dV2&) const;  //Метод скалярного произведения
	vector3dV2& operator = (const vector3dV2&);     //Перегрузка присваивания
	vector3dV2& operator = (const vector3d&);
};
vector3dV2& vector3dV2::operator = (const vector3dV2& T1)
{
	if (this != &T1)
	{
		x = T1.x;
		y = T1.y;
		z = T1.z;
		N.x0 = T1.N.x0;
		N.y0 = T1.N.y0;
		N.z0 = T1.N.z0;
	}
	return *this;
}
vector3dV2& vector3dV2::operator = (const vector3d& T1)
{
	if (this != &T1)
	{
		x = T1.getx();
		y = T1.gety();
		z = T1.getz();
	}
	return *this;
}
double vector3dV2::scalarproduct(const vector3dV2& T) const
{
	return (x*T.x+y*T.y+z*T.z);
}
void function(int a, ifstream& fin, ofstream& fout)   //Функция ввода, обработки и вывода 
{
	if (a == 0)
	{
		vector3d A, B;
		fin >> A >> B;
		fout << "Вектор суммы " << (A + B);
		return;
	}
	if (a == 2)
	{
		vector3dV2 A, B;
		fin >> A >> B;
		fout << "Вектор суммы " << (A + B);
		return;
	}
	if (a == 1)
	{
		vector3d A, B;
		fin >> A >> B;
		if (A > B)
			fout << "Длина вектора " << A << " больше длины вектора " << B << " на " << A.module() - B.module();
		else if (B > A)
			fout << "Длина вектора " << B << " больше длины вектора " << A << " на " << B.module() - A.module();
		else if (A == B)
			fout << "Векторы " << A << " и " << B << " равны";
		else
			fout << "Длины векторов " << A << " и " << B << " равны";
		return;
	}
	if (a == 3)
	{
		vector3dV2 A, B;
		fin >> A >> B;
		if (A > B)
			fout << "Длина вектора " << A << " больше длины вектора " << B << " на " << A.module() - B.module();
		else if (B > A)
			fout << "Длина вектора " << B << " больше длины вектора " << A << " на " << B.module() - A.module();
		else if (A == B)
			fout << "Векторы " << A << " и " << B << " равны";
		else
			fout << "Длины векторов " << A << " и " << B << " равны";
		return;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	if (fin.is_open()) //Проверка на открытие файла
	{
		int f;
		fin >> f;
		function(f, fin, fout);
		fin.close();      //Закрытие файлов
		fout.close();
	}
	return 0;
}