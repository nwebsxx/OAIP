#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

struct List {
	char name[30];
	char city[20];
	List* next;
	List* prev;
};

void addtoend(List* p, List** tail, List** head)
{
	if (*head == NULL) {    //если список пустой
	    *head = p;        //новый становится головой и хвостом
	    *tail = p;
		p->next = NULL;   //является конечным
		p->prev = NULL;
	}
	else {
		(*tail)->next = p;   //последний указывает на новый
		p->prev = *tail;  //новый на предыдущий
		p->next = NULL;
		*tail = p;
	}
}

List* create()
{
	List* temp = new List;
	cout << "Введите имя: ";
	cin.ignore();
	cin.getline(temp->name, 30);

	cout << "Введите город: ";
	cin.ignore();
	cin.getline(temp->city, 20);

	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void del(char* name, List** tail, List** head)
{
	List* temp = *head;
	while (temp != NULL) {
		if (strcmp(temp->name, name) == 0) {
			if (temp == *head && temp == *tail) {     //если он единственный
				*head = NULL;
				*tail = NULL;
			}
			else if (temp == *head) {     //если он первый
				*head = (*head)->next;
				(*head)->prev = NULL;
			}
			else if (temp == *tail) {      //если он последний
				*tail = (*tail)->prev;
				(*tail)->next = NULL;
			}
			else {
				temp->prev->next = temp->next;     //если между 2мя звеньями
				temp->next->prev = temp->prev;
			}
			delete temp;
			return;
		}
		temp = temp->next;
	}
}

void printlist(List* head)
{
	List* temp = head;

	while (temp != NULL) {
		cout << "Имя: " << temp->name << endl;
		cout << "Город: " << temp->city << endl;
		temp = temp ->next;
	}
}

void search(char* name, List* head)
{
	List* temp = head;

	while (temp != NULL) {
		if (strcmp(temp->name, name) == 0) {
			cout << temp->name;
			cout << temp->city;
		}
		temp = temp->next;
	}
}

void tofile(List* head)
{
	ofstream file("file.txt");

	if (!file.is_open()) {
		cout << "Ошибка открытия файла" << endl;
		return;
	}

	List* temp = head;
	while (temp != NULL) {
		file << temp->name;
		file << temp->city;
		temp = temp->next;
	}

	file.close();
}

void fromfile(List** head, List** tail, char* name, char* city)
{
	ifstream file("file.txt");

	if (!file.is_open()) {
		cout << "Ошибка открытия файла" << endl;
		return;
	}

	while (*head != NULL) {
		List* temp = *head;
		*head = (*head)->next;
		delete temp;
	}

	while (file >> name >> city) {
		List* newElement = new List;  
		addtoend(newElement, head, tail);
	}

	file.close();
}

void deletedouble(List** head)
{
	List* current = *head;

	while (current != NULL && current->next != NULL) {

		List* runner = current;
		while (runner->next != NULL) {   

			if (strcmp(current->name, runner->next->name) == 0) {
				List* extra = runner->next;
				runner->next = extra->next;
				if (extra->next) {
					extra->next->prev = runner;
				}
				delete extra;
			}	
			else {
				runner = runner->next;
			}
		}
		current = current->next;
	}
}


int main()
{
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);

	List* head = NULL;      //создание списка
	List* tail = NULL;

	char name[30];
	char city[20];

	int choice;
	do
	{
		cout << "1. Добавление в конец списка" << endl;
		cout << "2. Вывод списка на экран" << endl;
		cout << "3. Поиск имени в списке" << endl;
		cout << "4. Удаление имени" << endl;
		cout << "5. Запись в файл" << endl;
		cout << "6. Чтение из файла" << endl;
		cout << "7. Удаление повторяющихся элементов" << endl;
		cout << "8. Выход" << endl;
		cout << "9. Выберите действие: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			addtoend(create(), &tail, &head);
			break;
		case 2:
			printlist(head);
			break;
		case 3:
			cout << "Введите имя для поиска: ";
			cin.ignore();
			cin.getline(name, 30);
			search(name, head);
			break;
		case 4:
			cout << "Введите имя для удаления: ";
			cin.ignore();
			cin.getline(name, 30);
			del(name, &head, &tail);
			break;
		case 5:
			tofile(head);
			break;
		case 6:
			fromfile(&head, &tail, name, city);
		case 7:
			deletedouble(&head);
			break;
		case 8:
			break;
		}
	} while (choice != 8);

	return 0;
}

		