#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

int search(int num, const vector<int>& vt) {
	for (int k = 0; k < vt.size(); k++) {
		if (vt[k] == num)
			return 1;
	}
	return 0;
}
int searchvt(const vector <int>& num, const vector<vector<int>>& vt) {
	for (int k = 0; k < vt.size(); k++) {
		if (vt[k] == num)
			return 1;
	}
	return 0;
}
void sort(vector<int>& vt) {
	int a = 0;
	for (int l = 0; l < vt.size(); l++) {
		for (int k = 1; k < vt.size(); k++) {
			if (vt[k] < vt[k - 1]) {
				a = vt[k];
				vt[k] = vt[k - 1];
				vt[k - 1] = a;
			}
		}
	}
}
void randmass(vector<int>& vt) {
	int massnum, f = 1 + rand() % 99;
	cout << "Количество элементов в множестве: "; cin >> massnum;
	for (int l = 0; l < massnum; l++) {
		while (search(f, vt)) {
			f = 1 + rand() % 99;
		}
		vt.push_back(f);
	}
	sort(vt);
	cout << "Множество A:" << endl;
	for (int k : vt) cout << k << ' ';
}
void handmass(vector<int>& vt) {
	int massnum, num;
	cout << "Количество элементов в множестве: "; cin >> massnum;
	for (int l = 0; l < massnum; l++) {
		cout << "Введите " << l + 1 << " элемент: "; cin >> num;
		vt.push_back(num);
	}
	cout << "Множество A:" << endl;
	for (int k : vt) cout << k << ' ';
}
int max(const vector<int>& vt) {
	int max = 0;
	for (int k : vt) if (k > max) max = k;
	return max;
}
void full(const vector<int>& num, const vector<vector<int>>& vt) {
	int ye = 1;
	for (int m : num)
		for (int n : num)
			if (searchvt({ m, n }, vt) == 0)
				ye = 0;
	if (ye) cout << '\n' << "Множество полное";
	else cout << '\n' << "Множество не полное";
}
void diag(const vector<int>& num, const vector<vector<int>>& vt) {
	int ye = 1;
	for (int m : num)
		for (int n : num)
			if (searchvt({ m, m }, vt) == 0 or (searchvt({ m, n }, vt) == 1 and m != n))
				ye = 0;
	if (ye) cout << '\n' << "Множество диагональ";
	else cout << '\n' << "Множество не диагональ";
}
void ref(const vector<int>& num, const vector<vector<int>>& vt) {
	int ye = 1;
	for (int m : num)
		if (searchvt({ m, m }, vt) == 0)
			ye = 0;
	if (ye) cout << '\n' << "Множество рефлексивно";
	else cout << '\n' << "Множество не рефлексивно";
}
void simm(const vector<int>& num, const vector<vector<int>>& vt) {
	int ye = 1;
	for (int m : num)
		for (int n : num)
			if ((searchvt({ m, n }, vt) == 1 && searchvt({ n,m }, vt) == 0) or (searchvt({ m, n }, vt) == 0 && searchvt({ n,m }, vt) == 1))
				ye = 0;
	if (ye) cout << '\n' << "Множество симметрично";
	else cout << '\n' << "Множество не симметрично";
}
void asimm(const vector<int>& num, const vector<vector<int>>& vt) {
	int ye = 1;
	for (int m : num)
		for (int n : num)
			if ((searchvt({ m, n }, vt) == 1 && searchvt({ n,m }, vt) == 1) or (searchvt({ m, n }, vt) == 0 && searchvt({ n,m }, vt) == 0))
				ye = 0;
	if (ye) cout << '\n' << "Множество антисимметрично";
	else cout << '\n' << "Множество не антисимметрично";
}
void trans(const vector<vector<int>>& vt) {
	int ye = 1;
	for (int m = 0; m < vt.size(); m++)
		for (int n = 0; n < vt.size(); n++)
			if (m!=n and vt[m][1] == vt[n][0] and searchvt({ vt[m][0],vt[n][1] }, vt) == 0)
				ye = 0;
	if (ye == 1) {
		ye = 0;
		for (int m = 0; m < vt.size(); m++)
			for (int n = 0; n < vt.size(); n++)
				if (vt[m][1] == vt[n][0] and m!=n)
					ye = 1;
	}
	if (ye) cout << '\n' << "Множество транзитивно";
	else cout << '\n' << "Множество не транзитивно";
}
int main() {
	srand(time(0));
	char choise;
	setlocale(LC_ALL, "rus");
	vector<int> A;
	vector<vector<int>> C;
	cout << "Введение множества (1 - случайая генерацияm, 2 - ручной ввод): "; cin >> choise;
	switch (choise) {
	case '1':
		randmass(A);
		break;
	case '2':
		handmass(A);
		break;
	default:
		cout << "Неправильное значение.";
	}

	for (int a : A)
		for (int b : A)
			if ((b == 2 * a - 1) and searchvt({ a,b }, C) == 0) C.push_back({ a, b });  //(b == 2 * a - 1)

	cout << '\n' << '\n' << "Отношение b=2a-1: {";
	for (int i = 0; i < C.size(); i++) {
		cout << '{' << C[i][0] << ',' << C[i][1] << '}';
	}
	cout << '}' << '\n' << '\n';

	for (int k = 0; k <= to_string(max(A)).size(); k++) cout << ' ';
	for (int k : A) cout << k << ' ';
	cout << '\n';

	for (int i : A) {
		cout << i;
		for (int l = 0; l < (to_string(max(A)).size() + 1 - to_string(i).size()); l++) cout << ' ';
		for (int m : A) {
			if (searchvt({ i,m }, C)) {
				cout << 1;
				for (int k = 0; k < to_string(m).size(); k++) cout << ' ';
			}
			else {
				cout << 0;
				for (int k = 0; k < to_string(m).size(); k++) cout << ' ';
			}
		}
		cout << '\n';
	}

	full(A, C);
	diag(A, C);
	ref(A, C);
	simm(A, C);
	asimm(A, C);
	trans(C);

	return 0;
}
