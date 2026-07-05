//Горожанин. Ф.И.О., дата рождения, адрес, пол (м, ж). Реализовать выборку по году рождения. 

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

struct Citizen {
	string fio;
	int date;
	string adress;
	char gender;
};

struct Citizen list[100];
int k = 0;

int addcitizen()
{
	cout << "Добавите нового горожанина: " << endl;
	cout << "ФИО: "; 
	cin.ignore();
	getline(cin, list[k].fio);
	cout << "Дата рождения: ";
	cin >> list[k].date;
	cout << "Адрес проживания : ";
	cin.ignore();
	getline(cin, list[k].adress);
	cout << "Пол: ";
	cin >> list[k].gender;
	k++;

	return 0;
}

int showcitizen()
{
	cout << "Список горожан: " << endl;

	for (int i = 0; i < k; i++) {
		cout << "ФИО: " << list[i].fio << endl;
		cout << "Дата рождения: " << list[i].date << endl;
		cout << "Адрес проживания: " << list[i].adress << endl;
		cout << "Пол: " << list[i].gender << endl;
	}
	return 0;
}

int deletecitizen()
{
	int index;
	cout << "Номер гражданина для удаления: ";
	cin >> index;

	for (int i = index - 1; i < k - 1; i++) {
		list[i] = list[i + 1];
	}
	k--;

	return 0;
}

int searchcitizen()
{
	int year;
	cout << "Введите год для поиска горожан: ";
	cin >> year;

	for (int i = 0; i < k; i++) {
		if (list[i].date == year) {
			cout << "ФИО: " << list[i].fio;
			cout << "Дата рождения: " << list[i].date;
			cout << "Адрес проживания: " << list[i].adress;
			cout << "Пол: " << list[i].gender;
		}
	}
	return 0;
}

int writefile()
{
	ofstream file("citizens.txt");

	if (!file.is_open()) {
		cout << "Ошибка открытия файла" << endl;
		return 1;
	}

	file << k << endl;

	for (int i = 0; i < k; i++) {
		file << list[i].fio << endl;
		file << list[i].date << endl;
		file << list[i].adress << endl;
		file << list[i].gender << endl;
	}

	file.close();
	cout << "Записано в файл" << endl;
	return 0;
}

int readfile()
{
	ifstream file("citizens.txt");

	if (!file.is_open()) {
		cout << "Ошибка открытия файла" << endl;
		return 1;
	}

	int filek;
	file >> filek;
	file.ignore();

	k = 0;

	for (int i = 0; i < filek; i++) {
		getline(file, list[i].fio);
		file >> list[i].date;
		file.ignore();
		getline(file, list[i].adress);
		file.ignore();
		file >> list[i].gender;
	}

	file.close();
	cout << "Прочитано из файла" << endl;
	return 0;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);
	int choice;

	do
	{
		cout << "1. Добавить горожанина" << endl;
		cout << "2. Показать всех горожан" << endl;
		cout << "3. Удалить горожанина" << endl;
		cout << "4. Найти по году рождения" << endl;
		cout << "5. Записать в файл" << endl;
		cout << "6. Прочитать из файла" << endl;
		cout << "7. Выход" << endl;
		cout << "Выберите действие: ";
		cin >> choice;
		switch (choice) {
		case 1:
			addcitizen();
			break;
		case 2:
			showcitizen();
			break;
		case 3:
			deletecitizen();
			break;
		case 4:
			searchcitizen();
			break;
		case 5:
			writefile();
			break;
		case 6:
			readfile();
			break;
		case 7:
			break;
		}

	} while (choice != 7);

	return 0;
}