#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int main()
{
	 float x, y;
	string s;
	setlocale(LC_ALL, "rus");
	cout << "Введите координаты точки (x,y):"; cin >> x >> y;
	if (x >= 0)
	{
		if (x * x + y * y <= 1)
			s = "Точка принадлежит области";
		else
			s = "Точка не принадлежит области";
	}
	else
	{
		if (x>=abs(2*y) - 2)
			s = "Точка принадлежит области";
		else
			s = "Точка не принадлежит области";
	}
	cout << s;
	return 0;
}
