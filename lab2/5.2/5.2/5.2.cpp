// Ввести с клавиатуры строку символов, состоящую из цифр и слов, разделенных пробелами, и записать ее в файл. 
// Прочитать из файла данные и вывести нечетные числа строки. 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int write(ofstream& f, string str);
int read(ifstream& f, string str);

int main()
{
	setlocale(LC_CTYPE, "Russian");
	string str;
	cout << "Введите строку: " << endl;
	getline(cin ,str);

	ofstream fout;
	write(fout, str);

	ifstream fin;
	read(fin, str);

	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		int n = c - '0';
		if (c >= '0' && c <= '9' && n % 2 != 0) {
			cout << "Нечетное число в строке: " << n << endl;
		}
	}
	return 0;
}

int write(ofstream& f, string str)
{
	f.open("file3.txt");
	f << str;
	f.close();
	return 0;
}

int read(ifstream& f, string str)
{
	f.open("file3.txt");
	getline(f, str);
	f.close();
	return 0;
}
