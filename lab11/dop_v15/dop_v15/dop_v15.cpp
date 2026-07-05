#include <iostream>
#include <windows.h>
using namespace std;

struct Node {
	char data;
	Node* next;
};

void add(Node*& front, Node*& back, char value)
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

void addetalon(Node*& front, Node*& back)
{
	char etalon, value;

	cout << "Введите эталонный символ: ";
	cin >> etalon;

	do
	{
		cin >> value;

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
	} while (value != etalon);
}

int main()
{
	Node* front = NULL;
	Node* back = NULL;

	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);

	int choice;
	char value;

	do
	{
		cout << "1. Добавление элементов в очередь" << endl;
		cout << "2. Удаление элементов очереди" << endl;
		cout << "3. Вывод очереди" << endl;
		cout << "4. Удаление 2х элементов при встрече с эталоном" << endl;
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
			break;
		case 4:
		{
			addetalon(front, back);

			cout << "Вся очередь: ";
			print(front);

			if (front != NULL) {
				cout << "Удаляем " << del(front, back) << endl;
				if (front != NULL) {
					cout << "Удаляем " << del(front, back) << endl;
				}
			}

			cout << "Оставшаяся очередь: ";
			print(front);

			int count = 0;
			Node* current = front;
			while (current != NULL) {
				count++;
				current = current->next;
			} 
			cout << "Размер очереди = " << count << endl;
			break;
		}
		case 5:
			break;
		}

	} while (choice != 5);

	return 0;
}