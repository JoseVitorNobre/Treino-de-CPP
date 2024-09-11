#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define ll long long
#define pll pair<ll, int>

struct Node {
    ll v, w;
    bool train;
    Node(ll v, ll w, bool t) : v(v), w(w), train(t) {}
    Node() : v(-1), w(LLONG_MAX), train(0) {}
};

vector<ll> dis;
vector<bool> tt, marked;
int used = 0;

void dijkstra(vector<vector<Node>> &adj) {
    int n = adj.size();
    dis.resize(n, LLONG_MAX);
    tt.resize(n + 1, false);
    marked.resize(n + 1, false);
    dis[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, 1});

    while (!q.empty()) {
        int v = q.top().second;
        ll d = q.top().first;
        q.pop();

        if (d != dis[v] || marked[v]) continue;
        marked[v] = true;

        for (auto &u : adj[v]) {
            int to = u.v;
            ll len = u.w;
            bool train = u.train;

            if (dis[v] + len < dis[to] || (dis[v] + len == dis[to] && !train)) {
                tt[to] = train;
                dis[to] = dis[v] + len;
                q.push({dis[to], to});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<Node>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w, false);
        adj[b].emplace_back(a, w, false);
    }

    for (int i = 0; i < k; i++) {
        int a, w;
        cin >> a >> w;
        adj[1].emplace_back(a, w, true);
        adj[a].emplace_back(1, w, true);
    }

    dijkstra(adj);
    for (bool e : tt) {
        if (e) used++;
    }

    cout << k - used << '\n';
    return 0;
}
