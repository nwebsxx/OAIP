#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int n = 1000;
	int A[n];
	int B[n];

	srand(time(NULL));

	cout << "Исходный массив: " << endl;
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 100 + 1;
		B[i] = A[i];
		cout << B[i] << " ";
	}
	cout << endl;

	
	int d, count;
	d = n;
	d = d / 2;
	while (d > 0) {
		for (int i = 0; i < n - d; i++) {
			int j = i;
			while (j >= 0 && B[j] > B[j + d]) {
				swap(B[j], B[j + d]);
				j--;
			}
		}
		d = d / 2;
	}


	cout << "Сортировка Шелла: " << endl;
	for (int i = 0; i < 1000l; i++) {
		cout << B[i] << " ";
	}
	cout << endl;

	return 0;
}