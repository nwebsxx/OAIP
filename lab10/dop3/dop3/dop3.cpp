#include <iostream>
#include <deque>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
	deque <int> fish;

	int n;
	cout << "Введите количество рыб: ";
	cin >> n;

	int size;
	for (int i = 0; i < n; i++) {          //+ плывут по течению, - против
		cout << "Введите размеры рыб: ";
		cin >> size;
		fish.push_back(size);
	}

	deque <int> result;

    while (!fish.empty()) {               //если в исходном деке есть элементы, а в конечный пуст, удаляем из исх и добавляем в конеч
        int current = fish.front();
        fish.pop_front();

        if (result.empty()) {
            result.push_back(current);
        }
        else {
            int last = result.back();

            if (last > 0 && current < 0) {         //последний элемент в конеч деке больше текущего в исходном - продолжаем проверять
                if (abs(last) > abs(current)) {
                    continue; 
                }
                else if (abs(last) < abs(current)) {     //если меньше, переносим обратно в исх
                    result.pop_back();
                    fish.push_front(current); 
                }
                else {
                    result.pop_back();
                }
            }
            else {
                result.push_back(current);
            }
        }
    }

    cout << "Выжившие рыбы: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }

    return 0;
}





