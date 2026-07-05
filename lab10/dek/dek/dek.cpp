#include <iostream>
#include <deque>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	deque <int> dek;

	int n;
	cout << "Введите количество игроков: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {    //заполнение дека числами от 1 до n
		dek.push_back(i);
	}

	cout << "Игроки: " << endl;         //вывод игроков
	for (int i = 0; i < dek.size(); i++) {
		cout << dek[i] << " ";
	}
	cout << endl;

	int k;
	cout << "Введите k (k-й игрок удаляется): ";
	cin >> k;


	while (dek.size() > 1) {             //пока не останется 1 игрок
		for (int i = 1; i < k; i++) {      //k-1 раз переносятся элементы из начала в конец
			int first = dek.front();        //k-й игрок удаляется
			dek.pop_front(); 
			dek.push_back(first);
		}
		dek.pop_front();
	}

	cout << "Победил " << dek.front();

	return 0;
}