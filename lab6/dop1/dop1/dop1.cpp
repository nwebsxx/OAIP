//1. Определить структуру для представления информации о сданных студентом экзаменах, содержащую поля: 
// ФИО студента, число экзаменов, полученные оценки. 
// Определить функции для обработки отдельного объекта (например, для проверки, сданы ли все экзамены на 4 и 5). 
// Написать функцию для обработки массива структур. 
// В результате обработки требуется вычислить характеристику успеваемости студентов, 
// то есть отношение числа студентов, сдавших экзамены на 4 и 5, к общему числу студентов, в процентах. 

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Student {
    string fio;           
    int examCount;        
    int grades[10];       
};

bool isExcellent(Student s) {
    for (int i = 0; i < s.examCount; i++) {
        if (s.grades[i] != 4 && s.grades[i] != 5) {
            return false;  
        }
    }
    return true;  
}

void inputStudent(Student& s) {
    cout << "Введите ФИО студента: ";
    cin.ignore();
    getline(cin, s.fio);

    cout << "Введите количество экзаменов: ";
    cin >> s.examCount;

    cout << "Введите оценки: ";
    for (int i = 0; i < s.examCount; i++) {
        cin >> s.grades[i];
    }
}

void printStudent(Student s) {
    cout << "ФИО: " << s.fio << endl;
    cout << "Количество экзаменов: " << s.examCount << endl;
    cout << "Оценки: ";
    for (int i = 0; i < s.examCount; i++) {
        cout << s.grades[i] << " ";
    }
    cout << endl;

    if (isExcellent(s)) {
        cout << "Сдал все на 4 и 5" << endl;
    }
    else {
        cout << "Есть оценки ниже 4" << endl;
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);

    int n;  
    cout << "Введите количество студентов: ";
    cin >> n;

    Student students[100]; 

    for (int i = 0; i < n; i++) {
        cout << "Студент " << i + 1;
        inputStudent(students[i]);
    }

    
    cout << "ИНФОРМАЦИЯ О СТУДЕНТАХ" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Студент " << i + 1 << endl;
        printStudent(students[i]);
    }
   
    int excellentCount = 0;
    for (int i = 0; i < n; i++) {
        if (isExcellent(students[i])) {
            excellentCount++;
        }
    }
    
    float percent = (float)excellentCount / n * 100;

    cout << "Всего студентов: " << n << endl;
    cout << "Студентов, сдавших на 4 и 5: " << excellentCount << endl;
    cout << "Процент успеваемости: " << percent << "%" << endl;

    return 0;
}