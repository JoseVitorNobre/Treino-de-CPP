#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = LLONG_MAX;
const int MAXN = 1e6+10;


void dijkstra(int src, int n, int k, vector<pair<int, ll>> adj[]) {
    vector<vector<ll>> dist(n+1, vector<ll>(k, INF));
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, src});
    dist[src][0] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u][k-1]) continue;

        for (auto [v, w] : adj[u]) {
            ll new_dist = d + w;
            if (new_dist < dist[v][k-1]) {
                dist[v][k-1] = new_dist;
                pq.push({new_dist, v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << (dist[n][i] == INF ? -1 : dist[n][i]) << " ";
    }
    cout << endl;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, ll>> adj[n+1];

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(1, n, k, adj);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    solve();
    return 0;
}
