// Компоненты файла f – целые двухзначные числа (положительные и отрицательные). 
// Получить файл g, образованный из f включением только чисел кратных K.

#include <iostream>
#include <stdio.h>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	errno_t err;
	int size, k, i;
	FILE* f;

	printf("Введите размер: ");
	scanf_s("%d", &size);

	int* M = (int*)malloc(size * sizeof(int));

	printf("Введите числа в файл f (двухзначные):\n");
	for (i = 0; i < size; i++)
		scanf_s("%d", &M[i]);

	err = fopen_s(&f, "D:\\unik\\2sem\\oaip\\lab1\\f.txt", "w");

	if (err != 0) {
		perror("Error");
		return 1;
	}

	for (i = 0; i < size; i++)
		fprintf(f, "%d ", M[i]);
	fprintf(f, "\n");

	fclose(f);

	printf("Введите число для проверки кратности: ");
	scanf_s("%d", &k);

	err = fopen_s(&f, "D:\\unik\\2sem\\oaip\\lab1\\g.txt", "w");

	if (err != 0) {
		perror("Error");
		return 1;
	}
	int n = 0;
	for (i = 0; i < size; i++) {
		if (M[i] % k == 0) {
			fprintf(f, "%d ", M[i]);
			n++;
		}
	}

	fclose(f);

	printf("Числа в файле g:\n");
	for (i = 0; i < size; i++) {
		if (M[i] % k == 0) {
			printf("%d ", M[i]);
		}
	}

	free(M);
	return 0;
}