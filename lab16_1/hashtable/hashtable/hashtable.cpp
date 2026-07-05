#include <iostream>
using namespace std;

struct Hash {
	int table[100];
	int size;
	int c1;
	int c2;
};

int hashfunction(int key, int size)
{
	return key % size;
}

int squarefunction(int key, int size, int i, int c1, int c2)
{
	int h = hashfunction(key, size);
	return (h + c1 * i + c2 * i * i) % size;
}

void add(Hash& table, int key)
{
    int i = 0;
    int index;

    do {
        index = squarefunction(key, table.size, i, table.c1, table.c2);

        if (table.table[index] == 0) {
            table.table[index] = key;
            cout << "Добавлено " << key << endl;
            return;
        }
        i++;
    } while (i < table.size);
}

void search(Hash& table, int key)
{
    int i = 0;
    int index;

    while (i < table.size) {
        index = squarefunction(key, table.size, i, table.c1, table.c2);

        if (table.table[index] == key) {
            cout << "Найдено " << key << endl;
            return;
        }
        i++;
    }
}

bool del(Hash& table, int key)
{
    int i = 0;
    int index;

    while (i < table.size) {
        index = squarefunction(key, table.size, i, table.c1, table.c2);

        if (table.table[index] == key) {
            table.table[index] = 0; 
            cout << "Удалено " << key << endl;
            return true;
        }
        i++;
    }
    return false;
}

void printTable(Hash& table)
{
    for (int i = 0; i < table.size; i++) {
        if (table.table[i] != 0) {
            cout << i << "\t" << table.table[i] << endl;
        }
    }
    cout << endl;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");

	Hash table;
	table.size = 16;
	table.c1 = 1;
	table.c2 = 1;

    for (int i = 0; i < 100; i++) {
        table.table[i] = 0;
    }

	int choice, key;

    do
    {
        cout << "1. Добавить значение в таблицу" << endl;
        cout << "2. Удалить значение из таблицы" << endl;
        cout << "3. Поиск значения в таблице" << endl;
        cout << "4. Вывод таблицы" << endl;
        cout << "5. Выход" << endl;
        cout << "Выберите вариант: " << endl;
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Введите значение для добавления: ";
            cin >> key;
            add(table, key);
            break;
        case 2:
            cout << "Введите значение для удаления: ";
            cin >> key;
            del(table, key);
            break;
        case 3:
            cout << "Введите значение для поиска: ";
            cin >> key;
            search(table, key);
            break;
        case 4:
            printTable(table);
            break;
        case 5:
            break;
        }
    } while (choice != 5);

    return 0;
}

	