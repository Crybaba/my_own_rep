#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	float a, b, d, e, c, f, x, y;
	string s;
	cout << "Введите коэффициенты a, b, d, e: "; cin >> a >> b >> d >> e;
	cout << "Введите, чему равна правая часть первого и второго уравнений:"; cin >> c >> f;
	if (a / d == b / e and a / d != c / f)
		s= "Система не имеет решений.";
	else if (a/d==b/e and a/d == c/f)
		s = "Система имеет бесконечное количество решений.";
	else
	{
		y = (f - (d * c / a)) / (e - (d * b / a));
		x = (c - b * y) / a;
		s="Система имеет одно решение.";
	}
	cout << s << endl;
	if (s == "Система имеет одно решение.")
		cout <<"Корни: " <<endl<< "x = " << x <<endl<< "y = " << y;

	return 0;
}
