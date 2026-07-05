#include <iostream>
#include <stdarg.h>
#include <limits.h>
using namespace std;

void add(int** matrix, int size, int edges, ...)    //ф-ция с переменным кол-вом параметров для добавления ребер
{
	va_list args;    //список переменных аргументов
	va_start(args, edges);    //начало чтения аргументов

	for (int i = 0; i < edges; i++) {
		int from = va_arg(args, int);    
		int to = va_arg(args, int);      //определение аргументов
		int weight = va_arg(args, int);

		matrix[from][to] = weight;
	}
	va_end(args);      //конец чтения аргументов
} 

void floyd(int** matrix, int** result, int size)
{
	for (int i = 0; i < size; i++) {       //копируем исходную матрицу в конечную
		for (int j = 0; j < size; j++) {
			result[i][j] = matrix[i][j];
		}
	}

	for (int k = 0; k < size; k++) {        //алгоритм флойда
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (result[i][k] != INT_MAX && result[k][j] != INT_MAX) {
					int dist = result[i][k] + result[k][j];
					if (dist < result[i][j]) {
						result[i][j] = dist;
					}
				}
			}
		}
	}
}


int main()
{
	setlocale(LC_CTYPE, "Russian");

	const int size = 8;     //кол-во вершин не меньше 8

	int** matrix = new  int* [size];    //создание матрицы расстояний (исходная матрица)
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++) {
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = INT_MAX;
		}
	}

	cout << "Исходная матрица: " << endl;    //вывод исходной матрицы
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << " ";
		}
	}
	cout << endl;

	int** result = new int* [size];        //создание матрицы результата
	for (int i = 0; i < size; i++) {
		result[i] = new int[size];
	}

	add(matrix, size, 1, 0, 1, 3);
	 
	add(matrix, size, 2, 1, 2, 4, 2, 3, 5);            //обращения к ф-циям (не меньше 3-х)

	add(matrix, size, 3, 3, 4, 6, 4, 5, 7, 5, 6, 8);

	floyd(matrix, result, size);

	cout << "Матрица кратчайших расстояний: " << endl;     //вывод матрицы кратчайших расстояний
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (result[i][j] == INT_MAX)
				cout << "-" << " ";
			else
				cout << result[i][j] << " ";
		}
	}
	cout << endl;

	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
		delete[] result[i];
	}                      //освобождение памяти

	delete[] matrix;
	delete[] result;

	return 0;
}
