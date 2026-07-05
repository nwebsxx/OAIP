//Разработайте программу, которая позволяет пользователю добавлять, удалять и показывать задачи (например, запланированные задачи на день). 
// Используйте статические переменные для отслеживания количества задач и глобальные переменные для хранения массива задач. 
// Вводите данные с помощью локальных переменных.

#include <iostream> 
#include <string>
#include <windows.h>
using namespace std;

string zad[100];   //глобальная переменная для массива строк
static int k = 0;  //статическая глобальная переменная для кол-ва задач

int c()
{
	cout << " 1 введите фио ";
	char fio[50] = "";
	cin >> fio;
	cout << fio;
	return 0;
}

int g()
{
	cout << " 2 введите фио ";
	char fio2[50] = "";
	cin.ignore();
	cin.getline(fio2, 50);
	cout << fio2;
	return 0;
}

void add()
{
	cout << "Введите задачу: " << endl;
	cin.ignore();          
	getline(cin, zad[k]);  
	k++;
}

void del()
{
	int n;    //локальная (автоматическая) переменная 
	cout << "Номер задачи для удаления: ";
	cin >> n;
	for (int i = n - 1; i < k - 1; i++) {
		zad[i] = zad[i + 1];   
	}   
	k--;  
}

void all()
{
	for (int i = 0; i < k; i++) {
		cout << zad[i] << endl;
	}
}

int main()
{
	SetConsoleCP(1251);      
	setlocale(LC_CTYPE, "Russian");

	c();
	g();


	int choice;   //локальная (автоматическая) переменная 

	do {
		cout << "1 - добавить задачу" << endl;
		cout << "2 - удалить задачу" << endl;
		cout << "3 - показать все задачи" << endl;
		cout << "4 - выход" << endl;
		cout << "Выберите действие: ";
		cin >> choice;

		switch (choice)
		{
		case 1: 
			add();
			break;
		case 2:
			del();
			break;
		case 3:
			all();
			break;
		case 4:
			break;
		}

	} while (choice != 4);
	return 0;
}