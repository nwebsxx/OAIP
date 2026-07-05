// Скопировать в файл FILE2 только четные строки из FILE1. 
// Подсчитать размер файлов FILE1 и FILE2 (в байтах).

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	ifstream fin;
	fin.open("D:\\unik\\2sem\\oaip\\lab2\\FILE1.txt");

	ofstream fout;
	fout.open("FILE2.txt");

	if (!fin.is_open()) {
		cout << "Ошибка" << endl;
		return 1;
	}

	string str;
	int k = 1;
	while (getline(fin, str)) {
		if (k % 2 == 0) {
			fout << str << endl;
		}
		k++;
	}
	fin.close();
	fout.close();

	ifstream file1("D:\\unik\\2sem\\oaip\\lab2\\FILE1.txt", ios::binary);

	if (!file1.is_open()) {
		cout << "Ошибка" << endl;
		return 1;
	}

	file1.seekg(0, ios::end);
	int size1 = file1.tellg();
	file1.close();
	cout << "Размер FILE1: " << size1 << " байт" << endl;

	ifstream file2("D:\\unik\\2sem\\oaip\\lab2\\5.1\\5.1\\FILE2.txt", ios::binary);

	if (!file2.is_open()) {
		cout << "Ошибка" << endl;
		return 1;
	}

	file2.seekg(0, ios::end);
	int size2 = file2.tellg();
	file2.close();
	cout << "Размер FILE2: " << size2 << " байт" << endl;

	return 0;
}