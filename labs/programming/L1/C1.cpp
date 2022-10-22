#include <iostream>				//1 — радиус R
#include <cmath>					//2 — диаметр D = 2·R
using namespace std;				//3 — длина L = 2·р·R
int main()						//4 — площадь круга S = р·R2
{
	setlocale(LC_ALL, "rus");
	float n, R, D, L, S, p = 3.14;
	int sw;
	cout << "Введите номер элемента и его значение: ";
	cin >> sw >> n;
	switch (sw)
	{
	case 1:
		R = n;
		D = 2 * R;
		L = 2 * p * R;
		S = p * R * R;
		break;
	case 2:
		D = n;
		R = D / 2;
		L = 2 * p * R;
		S = p * R * R;
		break;
	case 3:
		L = n;
		R = L / (2 * p);
		D = 2 * R;
		S = p * R * R;
		break;
	case 4:
		S = n;
		R = sqrt(S / p);
		D = 2 * R;
		L = 2 * p * R;
		break;
	default:
		cout << "номер элемента введён неверно.";
		return 0;
	}
	cout << "Радиус R = " << R << endl
		<< "Диаметр D = " << D << endl
		<< "Длина L = " << L << endl
		<< "Площадь S = " << S;
	return 0;
}
