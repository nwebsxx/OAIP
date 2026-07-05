// Даны два файла целых чисел с именами fA и fB, содержащие элементы прямоугольных матриц M1 и M2 по строкам, 
// причем начальный элемент каждого файла содержит количество столбцов соответствующей матрицы. 
// Создать файл той же структуры с именем fC, содержащий произведение матриц M1·M2. 
// Если матрицы M1 и M2 нельзя перемножать, то оставить файл fC пустым.

#include <iostream>
#include <stdio.h>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int size1, size2, size3, i, j, k;

	FILE* f;
	errno_t err;

	printf("Введите размер матрицы M1: ");
	scanf_s("%d", &size1);

	int** M1 = (int**)malloc(size1 * sizeof(int*));
	for (i = 0; i < size1; i++)
		M1[i] = (int*)malloc(size1 * sizeof(int));

	printf("M1:\n");
	for (i = 0; i < size1; i++) {
		for (j = 0; j < size1; j++) {
			scanf_s("%d", &M1[i][j]);
		}
	}

	err = fopen_s(&f,"D:\\unik\\2sem\\oaip\\lab1\\fA.txt", "w");

	if (err != 0)
	{
		perror("Error");
		return 1;
	}

	for (i = 0; i < size1; i++)
		for (j = 0; j < size1; j++)
			fprintf(f, "%d ", M1[i][j]);

	fclose(f);

	printf("Введите размер матрицы M2: ");
	scanf_s("%d", &size2);

	int** M2 = (int**)malloc(size2 * sizeof(int*));
	for (i = 0; i < size2; i++)
		M2[i] = (int*)malloc(size2 * sizeof(int));

	printf("M2:\n");
	for (i = 0; i < size2; i++) {
		for (j = 0; j < size2; j++) {
			scanf_s("%d", &M2[i][j]);
		}
	}

	err = fopen_s(&f,"D:\\unik\\2sem\\oaip\\lab1\\fB.txt", "w");

	if (err != 0)
	{
		perror("Error");
		return 1;
	}

	for (i = 0; i < size2; i++)
		for (j = 0; j < size2; j++)
			fprintf(f, "%d ", M2[i][j]);

	fclose(f);

	int** M3 = (int**)malloc(size1 * sizeof(int*));
	for (i = 0; i < size1; i++)
		M3[i] = (int*)malloc(size2 * sizeof(int));

	if (size1 != size2) {
		printf("Нельзя умножить");
		return 1;
	}

	for (i = 0; i < size1; i++)
		for (j = 0; j < size2; j++)
			M3[i][j] = 0;

	for (i = 0; i < size1; i++)
		for (j = 0; j < size2; j++)
			for (k = 0; k < size1; k++) 
				M3[i][j] += M1[i][k] * M2[k][j];

	printf("M3:\n");
	for (i = 0; i < size1; i++) {
		for (j = 0; j < size2; j++) {
			printf("%d ", M3[i][j]);
		}
	}

	err = fopen_s(&f,"D:\\unik\\2sem\\oaip\\lab1\\fC.txt", "w");

	if (err != 0)
	{
		perror("Error");
		return 1;
	}

	if (size1 != size2) {
		fprintf(f, " ");
		return 1;
	}

	for (i = 0; i < size1; i++)
		for (j = 0; j < size2; j++)
			fprintf(f, " %d", M3[i][j]);
	fclose(f);

	for (i = 0; i < size1; i++)
		free(M1[i]);
	free(M1);
	for (i = 0; i < size2; i++)
		free(M2[i]);
	free(M2);
	for (i = 0; i < size1; i++)
		free(M3[i]);
	free(M3);
	return 0;
}