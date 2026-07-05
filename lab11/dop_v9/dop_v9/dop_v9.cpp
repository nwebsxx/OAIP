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

void create(Node*& originalfront, Node*& originalback, Node*& evenfront, Node*& evenback, Node*& oddfront, Node*& oddback)
{
	Node* current = originalfront;
	while (current != NULL) {
		if (current->data % 2 == 0) {
			add(evenfront, evenback, current->data);
			cout << "Четная = ";
			print(evenfront);
		}
		else if (current->data % 2 != 0) {
			add(oddfront, oddback, current->data);
			cout << "Нечетная = ";
			print(oddfront);
		}
		cout << endl;
		current = current->next;
	}
}

int size(Node* front)
{
	int count = 0;
	Node* current = front;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	cout << "Размер очереди = " << count << endl;
	return count;
}


int main()
{
	Node* front = NULL;
	Node* back = NULL;

	Node* evenfront = NULL;
	Node* evenback = NULL;

	Node* oddfront = NULL;
	Node* oddback = NULL;

	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);

	int choice;
	int value;

	do
	{
		cout << "1. Добавление элементов в очередь" << endl;
		cout << "2. Удаление элементов очереди" << endl;
		cout << "3. Вывод очереди" << endl;
		cout << "4. Создание 2 новых очереди (1 - чет., 2 - нечет.)" << endl;
		cout << "5. Определение размера очереди" << endl;
		cout << "6. Выход" << endl;
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
			create(front, back, evenfront, evenback, oddfront, oddback);
			break;
		case 5:
			size(front);
			break;
		case 6:
			break;
		}
	} while (choice != 6);

	return 0;
}