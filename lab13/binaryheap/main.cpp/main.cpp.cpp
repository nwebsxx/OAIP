#include "Heap.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);

	Heap* root = NULL;
	Heap* heap2 = NULL;

	int choice, value, index;
	do
	{
		cout << "1. Добавление в кучу" << endl;
		cout << "2. Удаление элемента кучи" << endl;
		cout << "3. Вывод кучи" << endl;
		cout << "4. Поиск значения" << endl;

		cout << "5. Удаление минимального элемента" << endl;
		cout << "6. Удаление i-го элемента" << endl;
		cout << "7. Объединение 2х куч в одну" << endl;

		cout << "8. Выход" << endl;
		cout << "Выберите вариант: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Введите число для добавления: ";
			cin >> value;
			add(root, value);
			break;
		case 2:
			value = del(root);
			break;
		case 3:
			if (root == NULL) {
				cout << "Пустая куча" << endl;
			}
			else {
				print(root);
				cout << endl;
			}
			break;
		case 4:
			cout << "Какое значение искать: ";
			cin >> value;
			find(root, value);
			if (find(root, value)) {
				cout << "Найден" << value << endl;
			}
			break;
		case 5:
			value = deletemin(root);
			cout << "Удален минимальный элемент: " << value << endl;
			break;
		case 6:
			cout << "Введите индекс: ";
			cin >> index;
			deleteindex(root, index);
			cout << "Удален элемент с индексом " << index << endl;
		    break;
		case 7:
			cout << "Сколько элементов добавить во вторую кучу? ";
			int count;
			cin >> count;
			for (int i = 0; i < count; i++) {
				cout << "Введите элемент " << i + 1 << ": ";
				cin >> value;
				add(heap2, value);
			}
			cout << "Вторая куча: ";
			print(heap2);
			cout << endl;

			unionheap(root, heap2);
			cout << "После объединения: ";
			print(root);
			cout << endl;
			break;
		case 8:
			break;
		}
	} while (choice != 8);

	return 0;
}