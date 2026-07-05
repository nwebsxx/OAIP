//Программа должна содержать меню с пунктами: 
// добавление элемента, удаление элемента, поиск элемента, вывод списка в консольное окно, запись списка в файл, считывание списка из файла. 
// Создать список, содержащий элементы целого типа. Найти сумму положительных элементов

#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

struct Node {
	int data;      //значение
	Node* next;    //указатель
};

void add(Node*& p, int value)      //*& ссылка на указатель на структуру, чтобы изменять сам указатель, а не данные
{
	Node* newp = new Node;
	if (newp != NULL) {     //если новый указатель указатель не последний
		newp->data = value;    //указывает на значение
		newp->next = p;       
		p = newp;
	}
	else
		cout << "Операция не выполнена" << endl;
}

void del(Node*& p, int value)
{
	if (p->data == value) {     
		Node* temp = p;     //временно сохраняем p
		p = p->next;  //p указывает на след.
		delete temp;  //удаляем 
		return;
	}
	
	Node* current = p;
	while (current->next && current->next->data != value) {
		current = current->next;
	}

	if (current->next) {
		Node* temp = current->next;  //временно сохраняем
		current->next = current->next->next;   //переносим
		delete temp;       //удаляем
	}
}

bool search(Node* p, int value)
{
	Node* current = p;
	while (current) {
		if (current->data == value) {    //если текущий указатель указывает на искомое значачение
			return true;
		}
		current = current->next;       //ищем дальше
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
		file << current->data << endl;    //выводим, двигаемся
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
		if (i->data > 0)
			sum += i->data;
	}
	cout << "Сумма положительных = " << sum << endl;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");     //004 УДК
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



