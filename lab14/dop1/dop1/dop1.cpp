#include <iostream>
using namespace std;

const int s = 10;
int graph[s][s];  // матрица смежности
bool visited[s];
int n, m;

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            k++;
        }
    }

    cout << "Количество компонент: " << k << endl;

    return 0;
}