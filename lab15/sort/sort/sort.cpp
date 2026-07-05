// Ввести массив А, в массив В скопировать все элементы массива А, имеющие четный индекс. 
// Массив В отсортировать по убыванию, используя алгоритмы сортировок: «пузырек», пирамидальная сортировка.
//Выполнить моделирование для массивов размером 1000 
// (в зависимости от быстродействия компьютера размеры массивов можно увеличивать). 

#include <iostream>
#include <time.h>
using namespace std;

void heap(int C[], int n, int i) {
    while (true) {
        int max = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && C[l] > C[max])
            max = l;
        if (r < n && C[r] > C[max])
            max = r;

        if (max == i) {
            break;
        }

        swap(C[i], C[max]);
        i = max;
    }
}

void sort(int C[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heap(C, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(C[0], C[i]);
        heap(C, i, 0);
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int A[1000];
    int B[1000];
    int C[1000];
    int count = 0;

    srand(time(NULL));

    for (int i = 0; i < 1000; i++) {
        A[i] = rand() % 100 + 1;
        if (i % 2 == 0) {
            B[count] = A[i];
            C[count] = A[i];
            count++;
        }
    }

    cout << "Исходный массив (" << count << " элементов): " << endl;
    for (int i = 0; i < count; i++) {
        cout << B[i] << " ";
    }
    cout << endl << endl;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (B[j] < B[j + 1]) {
                swap(B[j], B[j + 1]);
            }
        }
    }

    cout << "Пузырьковая сортировка: " << endl;
    for (int i = 0; i < count; i++) {
        cout << B[i] << " ";
    }
    cout << endl << endl;

    cout << "Пирамидальная сортировка: " << endl;
    sort(C, count);  

    for (int i = 0; i < count; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}