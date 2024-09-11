#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int to, weight;
};

void dijkstra(int n, const vector<vector<Edge>>& adj) {
    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, node] = pq.top(); pq.pop();
        if (d != dist[node]) continue;

        for (const auto& edge : adj[node]) {
            if (dist[node] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[node] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(Edge{b, c});
    }

    dijkstra(n, adj);
    return 0;
}