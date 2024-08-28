#include <bits/stdc++.h>

using namespace std;

vector<int> visited;
void dfs(int node, vector<vector<int>> &adj){
    if (visited[node]) return;
    visited[node] = 1;
    for (auto child : adj[node]) dfs(child, adj);
}

void solve(int n, vector<vector<int>> &adj){
    visited = vector<int>(n + 1);
    vector<int> nTBC; // nodes to be connected
    dfs(1, adj);
    for (int i = 2; i <= n; i++)
        if (!visited[i]){
            nTBC.push_back(i);
            dfs(i, adj);
        }

    cout << nTBC.size() << endl;
    for (auto node : nTBC) cout << "1 " << node << endl;
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(n, adj);
    return 0;
}