//разделить стек на 2 новых: 
//первый - элементы >50, воторой - остальные

#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& stack, int value)     //добавление
{
    Node* newp = new Node;
    newp->data = value;
    newp->next = stack;
    stack = newp;
}

int pop(Node*& stack)               //извлечение  
{
    int value = stack->data;
    Node* temp = stack;
    stack = stack->next;
    delete temp;
    return value;
}

void clear(Node*& stack)            //очистка
{
    while (stack != NULL) {
        Node* temp = stack;
        stack = stack->next;
        delete temp;
    }
}

void print(Node* stack)          //вывод
{
    Node* current = stack;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void writefile(Node* stack)    //запись в файл
{
    ofstream file("file.txt");
    if (!file.is_open()) {
        cout << "" << endl;
        return;
    }

    Node* current = stack;
    while (current != NULL) {
        file << current->data << " ";
        current = current->next;
    }

    file.close();
    cout << "Записано" << endl;

}

void readfile(Node* stack)          //чтение из файла
{
    ifstream file("file.txt");

    if (!file.is_open()) {
        cout << "" << endl;
        return;
    }

    int A[30];
    int count = 0;
    int value;

    while (file >> value) {
        A[count] = value;
        count++;
    }

    for (int i = 0; i < count; i++) {
        push(stack, A[i]);
    }

    file.close();
    cout << "Прочитано" << endl;
}


void separate(Node*& original, Node*& stack1, Node*& stack2)    //разделение на полож. и отриц.
{
    Node* current = original;

    while (current != NULL) {
        if (current->data > 50) {
            push(stack1, current->data);
        }
        else {
            push(stack2, current->data);
        }
        current = current->next;
    }

    cout << "Стек из элементов больше 50 : ";
    print(stack1);
    cout << "Стек из остальных элементов: ";
    print(stack2);
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);

    Node* stack = NULL;
    Node* stack1 = NULL;
    Node* stack2 = NULL;

    int choice, value;

    do
    {
        cout << "1. Добавить элемент в стек" << endl;
        cout << "2. Удалить элемент из стека" << endl;
        cout << "3. Очистить стек" << endl;
        cout << "4. Вывести стек" << endl;
        cout << "5. Разделить стек на 2 новых (1 - >50, 2 - остальные)" << endl;
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
            separate(stack, stack1, stack2);
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