#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int n, const vector<vector<pair<int, int>>>& adj) {
    vector<long long> dist(n + 1, LLONG_MAX);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue;

        for (const auto& [neighbor, weight] : adj[node]) {
            long long new_dist = dist[node] + weight;
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                parent[neighbor] = node;
                pq.push({new_dist, neighbor});
            }
        }
    }

    if (dist[n] == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        for (int node = n; node != -1; node = parent[node])
            path.push_back(node);
        for (auto it = path.rbegin(); it != path.rend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w); 
    }

    dijkstra(n, adj);

    return 0;
}