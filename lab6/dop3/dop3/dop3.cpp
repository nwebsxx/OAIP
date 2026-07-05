//. Определить структуру для представления информации о наличии санаторных путевок,
// содержащую следующие поля: Название санатория, Место расположения, Лечебный профиль, Количество путевок. 
// Представить введенные данные в виде таблицы, сгруппировав их по лечебным профилям санаториев. 
// В пределах каждой группы данные отсортировать по названиям санаториев. Организовать поиск информации и вывод результатов. 

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Sanatorium {
    string name;
    string location;
    string profile;
    int tickets;
};

int main() {
    setlocale(LC_CTYPE, "Russian");
    SetConsoleCP(1251);

    int n;
    cout << "Сколько санаториев? ";
    cin >> n;

    Sanatorium s[100];

    for (int i = 0; i < n; i++) {
        cout << "\nСанаторий " << i + 1 << endl;
        cout << "Название: ";
        cin.ignore();
        getline(cin, s[i].name);
        cout << "Место: ";
        getline(cin, s[i].location);
        cout << "Профиль: ";
        getline(cin, s[i].profile);
        cout << "Путевок: ";
        cin >> s[i].tickets;
    }

    string profiles[100];
    int pCount = 0;

    for (int i = 0; i < n; i++) {
        bool newProfile = true;
        for (int j = 0; j < pCount; j++) {
            if (s[i].profile == profiles[j]) {
                newProfile = false;
                break;
            }
        }
        if (newProfile) {
            profiles[pCount] = s[i].profile;
            pCount++;
        }
    }

    cout << "САНАТОРИИ ПО ПРОФИЛЯМ" << endl;

    for (int p = 0; p < pCount; p++) {
        Sanatorium temp[100];
        int tCount = 0;

        for (int i = 0; i < n; i++) {
            if (s[i].profile == profiles[p]) {
                temp[tCount] = s[i];
                tCount++;
            }
        }
        for (int i = 0; i < tCount - 1; i++) {
            for (int j = 0; j < tCount - i - 1; j++) {
                if (temp[j].name > temp[j + 1].name) {
                    Sanatorium x = temp[j];
                    temp[j] = temp[j + 1];
                    temp[j + 1] = x;
                }
            }
        }

        cout << profiles[p] << " ---" << endl;
        for (int i = 0; i < tCount; i++) {
            cout << "  " << i + 1 << ". " << temp[i].name << endl;
            cout << "     Место: " << temp[i].location << endl;
            cout << "     Путевок: " << temp[i].tickets << endl;
        }
    }
    cout << "ПОИСК" << endl;

    int choice;
    cout << "Искать по: 1-названию, 2-месту, 3-профилю: ";
    cin >> choice;
    cin.ignore();

    string word;
    cout << "Введите что искать: ";
    getline(cin, word);

    bool found = false;
    cout << "РЕЗУЛЬТАТЫ:" << endl;

    for (int i = 0; i < n; i++) {
        bool match = false;
        if (choice == 1 && s[i].name.find(word) != string::npos) match = true;
        if (choice == 2 && s[i].location.find(word) != string::npos) match = true;
        if (choice == 3 && s[i].profile.find(word) != string::npos) match = true;

        if (match) {
            cout << "Название: " << s[i].name << endl;
            cout << "Место: " << s[i].location << endl;
            cout << "Профиль: " << s[i].profile << endl;
            cout << "Путевок: " << s[i].tickets << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Ничего не найдено!" << endl;
    }

    return 0;
}