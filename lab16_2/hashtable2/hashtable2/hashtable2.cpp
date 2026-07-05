#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Hash {
	string name;
	int key;
	Hash* next;
};

const int S = 16;
Hash* table[S];

int hashfunction(int key)
{
	int p = 2027;  
	int a = rand() % (p - 1) + 1;
	int b = rand() % p;

	return ((a * key + b) % p) % S;
}

void add(string name, int key)
{
	int index = hashfunction(key);
	Hash* newp = new Hash;
	newp->name = name;
	newp->key = key;
	newp->next = table[index];
	table[index] = newp;
}

void print()
{
	for (int i = 0; i < S; i++) {
		Hash* current = table[i];
		while (current != NULL) {
			cout << i;
			cout << "\t" << current->name;
			cout << "\t" << current->key << endl;
			current = current->next;
		}
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);

	for (int i = 0; i < S; i++) {
		table[i] = NULL;
	}

	int choice, key;
	string name;

	do
	{
		cout << "1. Добавление товаров" << endl;
		cout << "2. Вывод таблицы" << endl;
		cout << "3. Выход" << endl;
		cout << "Выберите действие: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Введите название товара: ";
			cin >> name;
			cout << "Введите год выпуска: ";
			cin >> key;
			add(name, key);
			break;
		case 2:
			cout << "i";
			cout << "\tТовар";
			cout << "\tГод выпуска" << endl;
			print();
			break;
		case 3:
			break;
		}
	} while (choice != 3);

	return 0;
}
