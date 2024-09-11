#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = (s[j] == '#');
        }
    }

    int ans = 0;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) continue;
            ans++;
            stack<pair<int, int>> s;
            s.push({i, j});
            a[i][j] = 1;

            while (!s.empty()) {
                auto [r, c] = s.top();
                s.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dx[k], nc = c + dy[k];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m || a[nr][nc]) continue;
                    a[nr][nc] = 1;
                    s.push({nr, nc});
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
