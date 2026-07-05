#include <iostream>
using namespace std;

const int s = 100;
int graph[s][s];  // матрица смежности
bool visited[s];
int n, m;
int current;  // размер текущей компоненты

void dfs(int v) {
    visited[v] = true;
    current++;  // увеличиваем счётчик при посещении вершины

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    cout << "Введите количество вершин и рёбер: ";
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = false;
    }

    cout << "Введите рёбра (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;  // неориентированный граф
    }

    int max = 0;  // размер самой большой компоненты

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            current = 0;      // обнуляем счётчик для новой компоненты
            dfs(i);               // обходим компоненту
            if (current > max) {
                max = current;  // запоминаем максимальный размер
            }
        }
    }

    cout << "\nРазмер самой крупной компоненты: " << max << endl;

    return 0;
}