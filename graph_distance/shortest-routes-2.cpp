#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int MAXN = 505;

ll mat[MAXN][MAXN];
int n, m;

void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (mat[i][k] < INF && mat[k][j] < INF) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }
}

int main() {
    int q;
    cin >> n >> m >> q;

    // Inicializando a matriz de distâncias
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            mat[i][j] = (i == j) ? 0 : INF;
        }
    }

    // Lendo as arestas
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        mat[a][b] = mat[b][a] = min(mat[a][b], c);
    }

    floyd();

    // Respondendo as consultas
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (mat[x][y] == INF) {
            cout << -1 << endl;
        } else {
            cout << mat[x][y] << endl;
        }
    }

    return 0;
}
