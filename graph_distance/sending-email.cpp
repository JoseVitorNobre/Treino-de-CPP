#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, weight;
};

void dijkstra(int n, int S, int T, const vector<vector<Edge>>& adj, int case_num) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [curr_dist, node] = pq.top();
        pq.pop();

        if (curr_dist > dist[node]) continue;

        for (const auto& edge : adj[node]) {
            int new_dist = curr_dist + edge.weight;
            if (new_dist < dist[edge.to]) {
                dist[edge.to] = new_dist;
                pq.push({new_dist, edge.to});
            }
        }
    }

    cout << "Case #" << case_num << ": " 
         << (dist[T] == INT_MAX ? "unreachable" : to_string(dist[T])) 
         << endl;
}

int main() {
    int N;
    cin >> N;
    
    for (int case_num = 1; case_num <= N; ++case_num) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;

        vector<vector<Edge>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        dijkstra(n, S, T, adj, case_num);
    }
    
    return 0;
}
