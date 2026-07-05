#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");

	int A[1000];
	int B[1000];

	srand(time(NULL));

	cout << "Исходный массив: " << endl;
	for (int i = 0; i < 1000; i++) {
		A[i] = rand() % 100 + 1;
		B[i] = A[i];
		cout << B[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 1000; i++) {
		int min = i;
		for (int j = i + 1; j < 1000; j++)
			min = (B[j] < B[min]) ? j : min;
		if (i != min) {
			int buff = B[i];
			B[i] = B[min];
			B[min] = buff;
		}
	}

	cout << "Сортировка выбором: " << endl;
	for (int i = 0; i < 1000; i++) {
		cout << B[i] << " ";
	}
	cout << endl;

	return 0;
}