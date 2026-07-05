#include "stack.h"
#include <iostream>
#include <fstream>
using namespace std;

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


void separate(Node*& original, Node*& postack, Node*& negstack)    //разделение на полож. и отриц.
{
    Node* current = original;

    while (current != NULL) {
        if (current->data > 0) {
            push(postack, current->data);
        }
        else if (current->data < 0) {
            push(negstack, current->data);
        }
        current = current->next;
    }

    cout << "Положительный стек: ";
    print(postack);
    cout << "Отрицательный стек: ";
    print(negstack);
}