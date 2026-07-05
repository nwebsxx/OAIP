//разделить стек на 2 новых стека: 
//первый - положительные эл, второй - отрицательные

#include "stack.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);

    Node* stack = NULL;
    Node* postack = NULL;
    Node* negstack = NULL;

    int choice, value;

    do
    {
        cout << "1. Добавить элемент в стек" << endl;
        cout << "2. Удалить элемент из стека" << endl;
        cout << "3. Очистить стек" << endl;
        cout << "4. Вывести стек" << endl;
        cout << "5. Разделить стек на 2 новых" << endl;
        cout << "6. Запись в файл" << endl;
        cout << "7. Чтение из файла" << endl;
        cout << "8. Выход" << endl;
        cout << "Выберите вариант: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Введите элемент для добавления: ";
            cin >> value;
            push(stack, value);
            break;

        case 2:
            pop(stack);
            break;

        case 3:
            clear(stack);
            break;

        case 4:
            print(stack);
            break;

        case 5:
            separate(stack, postack, negstack);
            break;
        case 6:
            writefile(stack);
            break;
        case 7:
            readfile(stack);
            break;
        case 8:
            break;
        }
    } while (choice != 8);

    return 0;
}