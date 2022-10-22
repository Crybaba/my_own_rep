#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	char c;
	int k, count = -1;
	cout << "Введите строку ('Enter' - конец ввода): ";
	c = getchar();
	if (c >= '0' and c <= '9') {
		k = atoi(&c);
		do {
			c = getchar();
			if (c >= '0' and c <= '9') {
				cout << endl << "Условие не выполняется";
				return 0;
			}
			count++;
		} while (c != '\n');
	}

	else{
		cout << endl << "Условие не выполняется";
		return 0;
	}
	if (k == count) cout << endl<< "Условие выполняется";
	else cout << endl << "Условие не выполняется";
	return 0;
}
