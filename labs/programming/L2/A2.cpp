#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;


long double fact(int n) {
	long double y = 1;
	for (int k = 2; k <= n; k++) y *= k;
	return y;
}
void rate(long double x, long double a) {
	long double eps, y = 0, k = 1, pi = 3.1415926535;
	int n = 0;
	while (true) {
		cout << "Введите eps(0<eps<1): "; cin >> eps; cout << '\n';
		if (eps < 1 and eps>0) break;
		else cout << "Введено неправильное значение, введите снова.\n";
	}
	while (fabs(k) > eps) {
		k = pow(x, n) * cos(a + n * pi / 2) / fact(n);
		y += k;
		n++;
	}
	cout << "\ny = " << y << "\ny = " << scientific << y;
}
void given(long double x, long double a) {
	string sn;
	int n, brkg;
	char m;
	long double y = 0, pi = 3.1415926535;
	while (true) {
		brkg = 1;
		sn = "";
		cout << "Введите n>=0: ";
		m = getchar();
		sn += m;
		if ((m < '0' or m>'9') and m != '\n') brkg = 0;
		do {
			m = getchar();
			sn += m;
			if ((m < '0' or m>'9') and m != '\n') brkg = 0;
		} while (m != '\n');

		if (brkg == 1) {
			n = stoi(sn);
			if (n >= 0) break;
		}
		else cout << "Введено неправильное значение, введите снова.\n";
	}

	for (int k = 0; k <= n; k++) {
		y += pow(x, k) * cos(a + k * pi / 2) / fact(k);
	}
	cout << "\ny = " << y << "\ny = " << scientific << y;
}
void def(long double x, long double a) {
	long double y;
	y = cos(x + a);
	cout << "\ny = " << y << "\ny = " << scientific << y;
}

int main() {
	setlocale(LC_ALL, "rus");
	int choise, brkm;
	while (true) {
		cout << "\nкак производить расчет(1 - до погрешности, 2 - до заданного члена ряда, 3 - по функции): "<<setprecision(10);
		cin >> choise;
		if (choise > 0 and choise < 4) break;
		cout << "\nНеправильное значение.";
	}
	long double x, a;
	string sx, sa;

	while (true) {
		brkm = 1;
		cout << "Введите x(-1<x<1), a: "; cin >> sx >> sa; cout << '\n';
		for (char m : sx)
			for (char n : sa) {
				if (((m < '0' or m>'9') and m != ',') or ((n < '0' or n>'9') and n != ',')) brkm = 0;
			}
		if (brkm == 1) {
			a = stof(sa); x = stof(sx);
		}
		if (brkm == 1 and fabs(x) < 1) break;
		else cout << "Какое-то из значений введено неверно, введите снова.\n";
	}

	switch (choise) {
	case 1:
		rate(x, a);
		break;
	case 2:
		given(x, a);
		break;
	case 3:
		def(x, a);
		break;
	}
	return 0;
}
