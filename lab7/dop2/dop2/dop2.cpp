//2. Создать список, содержащий элементы целого типа. Найти сумму отрицательных элементов, кратных 2.

#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void add(Node*& p, int value)
{
	Node* newp = new Node;
	if (newp != NULL) {
		newp->data = value;
		newp->next = p;
		p = newp;
	}
	else
		cout << "Операция не выполнена" << endl;
}

void del(Node*& p, int value)
{
	if (p->data == value) {    
		Node* temp = p;     
		p = p->next;  
		delete temp;  
		return;
	}

	Node* current = p;
	while (current->next && current->next->data != value) {
		current = current->next;
	}

	if (current->next) {
		Node* temp = current->next;
		current->next = current->next->next;
		delete temp;
	}
}

bool search(Node* p, int value)
{
	Node* current = p;
	while (current) {
		if (current->data == value) {
			return true;
		}
		current = current->next;
	}
	return false;
	cout << "Элемент найден" << endl;
}

void printlist(Node*& p)
{
	Node* current = p;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void writetofile(Node*& p)
{
	ofstream file("file.txt");

	if (!file.is_open()) {
		cout << "Ошибка открытия файла" << endl;
		return;
	}

	Node* current = p;
	while (current != NULL) {
		file << current->data << endl;
		current = current->next;
	}

	file.close();
	cout << "Записано в файл" << endl;
}

void readfromfile(Node*& p)
{
	ifstream file("file.txt");

	if (!file.is_open()) {
		cout << "Ошибка открытия файла" << endl;
		return;
	}

	int value;
	while (file >> value) {
		Node* newp = new Node;
		newp->data = value;
		newp->next = p;
		p = newp;
	}

	file.close();
	cout << "Прочитано из файла" << endl;
}

void sum(Node*& p)
{
	int sum = 0;
	for (Node* i = p; i != NULL; i = i->next) {
		if (i->data < 0 && i->data % 2 == 0)
			sum += i->data;
	}
	cout << "Сумма положительных = " << sum << endl;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);

	Node* p = NULL;
	int value, choice;

	do
	{
		cout << "1. Добавление элемента" << endl;
		cout << "2. Удаление элемента" << endl;
		cout << "3. Поиск элемента" << endl;
		cout << "4. Вывод списка" << endl;
		cout << "5. Запись в файл" << endl;
		cout << "6. Чтение из файла" << endl;
		cout << "7. Сумма положительных элементов" << endl;
		cout << "8. Выход" << endl;
		cout << "9. Выберите действие: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Введите элемент для добавления: ";
			cin >> value;
			cout << endl;
			add(p, value);
			break;
		case 2:
			cout << "Введите элемент для удаления: ";
			cin >> value;
			cout << endl;
			del(p, value);
			break;
		case 3:
			cout << "Введите элемент для поиска: ";
			cin >> value;
			cout << endl;
			search(p, value);
			break;
		case 4:
			printlist(p);
			break;
		case 5:
			writetofile(p);
			break;
		case 6:
			readfromfile(p);
			break;
		case 7:
			sum(p);
			break;
		case 8:
			break;
		}
	} while (choice != 8);

	return 0;
}



