#include <iostream>
using namespace std;

const int s = 15;
int g[s][s], n, m, b = s;
int cover[s];

bool isCover(int mask) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (g[i][j]) {
                bool covered = (mask >> i) & 1 || (mask >> j) & 1;
                if (!covered) 
                    return false;
            }
        }
    }
    return true;
}

int count(int mask) {
    int cnt = 0;
    while (mask) { cnt += mask & 1; mask >>= 1; }
    return cnt;
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }

    int mask = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (isCover(mask)) {
            int cnt = count(mask);
            if (cnt < b) {
                b = cnt;
                mask = mask;
            }
        }
    }

    cout << "Минимальное вершинное покрытие: ";
    for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) cout << i << " ";
    }
    cout << endl;

    return 0;
}