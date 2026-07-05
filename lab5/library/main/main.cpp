#include <iostream>
#include <string>
#include <windows.h>
#include "library.h"
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);
	string str;
	cout << "Введите строку: ";
	getline(cin, str);

	turn(str);

	up(str);

	string substr;

    get(str, substr);

	cout << "Введите подстроку: ";
	cin.ignore();
	getline(cin, substr);

	pos(str, substr);

	return 0;
}