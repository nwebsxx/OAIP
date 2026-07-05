#include <iostream>
#include <windows.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void add(Node*& front, Node*& back, int value)
{
	Node* newnode = new Node;
	newnode->data = value;
	newnode->next = NULL;
	if (front == NULL) {
		front = newnode;
		back = newnode;
	}
	else {
		back->next = newnode;
		back = newnode;
	}
}

char del(Node*& front, Node*& back)
{
	int value = front->data;
	Node* temp = front;
	front = front->next;

	delete temp;
	return value;
}

void print(Node* front)
{
	Node* current = front;
	while (current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void create(Node*& originalfront, Node*& originalback, Node*& posfront, Node*& posback, Node*& negfront, Node*& negback)
{
	Node* current = originalfront;
	while (current != NULL) {
		if (current->data > 0) {
			add(posfront, posback, current->data);
			cout << "Положительный = ";
			print(posfront);
			cout << endl;
		}
		else if (current->data < 0) {
			add(negfront, negback, current->data);
			cout << "Отрицательный = ";
			print(negfront);
		}
		cout << endl;
		current = current->next;
	}
}


int main()
{
	Node* front = NULL;
	Node* back = NULL;

	Node* posfront = NULL;  
	Node* posback = NULL;

	Node* negfront = NULL; 
	Node* negback = NULL;

	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);

	int choice;
	int value;

	do
	{
		cout << "1. Добавление элементов в очередь" << endl;
		cout << "2. Удаление элементов очереди" << endl;
		cout << "3. Вывод очереди" << endl;
		cout << "4. Создание 2 новых очереди (1 - полож., 2 - отриц.)" << endl;
		cout << "5. Выход" << endl;
		cout << "Выберите вариант: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Введите число для добавления: ";
			cin >> value;
			add(front, back, value);
			break;
		case 2:
			del(front, back);
			break;
		case 3:
			print(front);
		case 4:
			create(front, back, posfront, posback, negfront, negback);
			break;
		case 5:
			break;
		} 
	} while (choice != 5);

	return 0;
}