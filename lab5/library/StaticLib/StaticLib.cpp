#include "library.h"
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int turn(string str)         
{
	int length = str.length();
	cout << "Перевернутая строка: ";
	for (int i = str.length() - 1; i >= 0; i--) {
		cout << str[i];
	}
	cout << endl;
	return 0;
}

int up(string str)     
{
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
		}
		if (str[i] >= 'а' && str[i] <= 'я') {
			str[i] = str[i] - 32;
		}
	}
	cout << "Строка в верхнем регистре: " << str << endl;
	return 0;
}

int get(string str, string substr)      
{
	int index, length;
	cout << "Введите индекс подстроки: ";
	cin >> index;
	cout << "Введите длину подстроки: ";
	cin >> length;

	string stroka = str.substr(index, length);
	cout << "Извлеченная подстрока: " << stroka << endl;
	return 0;
}

int pos(string str, string substr)     
{ 
	int stroka = str.length();
	int podstroka = substr.length();

	int result = -1;

	for (int i = 0; i <= stroka - podstroka; i++) {
		int count = 0;
		for (int j = 0; j < podstroka; j++) {
			if (str[i + j] == substr[j]) {
				count++;
			}
		}
		if (count == podstroka) {
			result = i;
		}
	}
	cout << "Позиция вхождения подстроки в строку: " << result << endl;
	return 0;
}




