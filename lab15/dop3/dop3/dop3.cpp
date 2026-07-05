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

	for (int i = 1; i < 1000; i++) {
		int buff = B[i];
		int j;
		for (j = i - 1; j >= 0 && B[j] > buff; j--) {
			B[j + 1] = B[j];
		}
		B[j + 1] = buff;
	}

	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < 1000; i++) {
		cout << B[i] << " ";
	}
	cout << endl;

	return 0;
}