#pragma once

struct Node {
    int data;
    Node* next;
};

void push(Node*& stack, int value);     //добавление
int pop(Node*& stack);              //извлечение  
void clear(Node*& stack);           //очистка
void print(Node* stack);         //вывод
void writefile(Node* stack);    //запись в файл
void readfile(Node* stack);         //чтение из файла
void separate(Node*& original, Node*& postack, Node*& negstack);    //разделение на полож. и отриц.

