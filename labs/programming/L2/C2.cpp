#include <iostream>
#include <cmath>
using namespace std;
int main(){
	unsigned int n, m=1;
	setlocale(LC_ALL, "rus");
	cout << "Введите число N: "; cin >> n;
	cout << "   x y z\n";
	for (int x = 0; x <= sqrt(n - 2); x++)
		for (int y = 0; y <= sqrt(n - 2); y++)
			for (int z = 0; z <= sqrt(n - 2); z++)
				if (pow(x, 2) + pow(y, 2) + pow(z, 2) == n){
					cout << m << ". " << x << ' ' << y << ' ' << z << endl;
					m++;
				}
	return 0;
}
