#include <iostream>
#include <deque>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");

    deque<int> zaprosi;  // Дек для всех запросов
    int n, etag, tip;

    cout << "Введите количество запросов: ";
    cin >> n;

    cout << "Введите запросы (этаж и тип 1-снаружи,2-изнутри):";

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        cin >> etag >> tip;

        if (tip == 2) {
            zaprosi.push_front(etag);
        }
        else {
            zaprosi.push_back(etag);
        }
    }

    int tekushiy = 1;  

    while (zaprosi.size() > 0) {
        int etaz = zaprosi.front();
        zaprosi.pop_front();

        if (etaz > tekushiy) {
            cout << "Вверх на " << etaz << " этаж ";
        }
        else if (etaz < tekushiy) {
            cout << "Вниз на " << etaz << " этаж ";
        }
        else {
            cout << "Остановка на " << etaz << " этаже ";
        }

        tekushiy = etaz;
    }

    cout << "Остановился на " << tekushiy << " этаже ";

    return 0;
}