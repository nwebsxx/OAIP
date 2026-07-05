//2. Описать структуру с именем TRAIN, содержащую поля: 
// названия пункта назначения, номер поезда, время отправления. 
// Написать программу, выполняющую ввод с клавиатуры данных в массив, 
// состоящий из восьми элементов типа TRAIN (записи должны быть размещены в алфавитном порядке по названиям пунктов назначения); 
// вывод на экран информации о поездах, отправляющихся после введенного с клавиатуры времени (если таких поездов нет, то вывести сообщение об этом).

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Train {
    string city;   
    int num;        
    int h;          
    int m;          
};

int main() {
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);

    const int N = 8;
    Train t[8];
    
    cout << "Введите данные о 8 поездах:\n";
    for (int i = 0; i < N; i++) {
        cout << "Поезд " << i + 1 << endl;
        cout << "Пункт назначения: ";
        cin.ignore();
        getline(cin, t[i].city);
        cout << "Номер поезда: ";
        cin >> t[i].num;
        cout << "Время (часы минуты): ";
        cin >> t[i].h >> t[i].m;
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (t[j].city > t[j + 1].city) {
                Train temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    cout << " Список поездов (по алфавиту) ";
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << t[i].city << endl;
        cout << "   Номер: " << t[i].num << endl;
        cout << "   Отправление: ";
        if (t[i].h < 10) cout << "0";
        cout << t[i].h << ":";
        if (t[i].m < 10) cout << "0";
        cout << t[i].m << endl;
    }

    int searchH, searchM;
    cout << "Введите время (часы минуты): ";
    cin >> searchH >> searchM;

    cout << "Поезда после " << searchH << ":";
    if (searchM < 10) cout << "0";
    cout << searchM;

    bool found = false;
    for (int i = 0; i < N; i++) {
        if (t[i].h > searchH || (t[i].h == searchH && t[i].m > searchM)) {
            cout << t[i].city << endl;
            cout << "Номер: " << t[i].num << endl;
            cout << "Время: ";
            if (t[i].h < 10) cout << "0";
            cout << t[i].h << ":";
            if (t[i].m < 10) cout << "0";
            cout << t[i].m << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Нет поездов после указанного времени!";
    }

    return 0;
}