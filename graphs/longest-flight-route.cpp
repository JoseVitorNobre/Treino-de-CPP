#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<int> g[100005], dp(100005, -1), c(100005);
vector<bool> was(100005);

void dfs(int v) {
    was[v] = true;

    for (int to : g[v]) {
        if (!was[to]) dfs(to);
        if (dp[to] != -1 && dp[to] + 1 > dp[v]) {
            dp[v] = dp[to] + 1;
            c[v] = to;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    dp[n] = 1;
    dfs(1);

    if (dp[1] == -1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << dp[1] << "\n";
        for (int v = 1; v; v = c[v]) cout << v << " ";
    }
}
