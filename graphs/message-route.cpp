#include <bits/stdc++.h>

using namespace std;
#define ll long long int

ll n, m;
vector<vector<ll>> graph;
vector<ll> par;
vector<ll> visited;

void bfs(){
	visited[1] = 1;
	queue<ll> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v: graph[u]){
			if(!visited[v]){
				visited[v] = 1;
				par[v] = u;
				q.push(v);
			}
		}
	} 
}

int main(){
    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1);
    par.resize(n + 1);
    
    for(int i = 0; i <= n; i++) par[i] = -1;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs();

    if(par[n] == -1) cout << "IMPOSSIBLE" << endl;
    else{
    	stack<int> path;
    	int u = n;
    	while(u != -1){
			path.push(u);
			u = par[u];
    	}

		cout << path.size() << endl;

		while(!path.empty()){
			cout << path.top() << " ";
			path.pop();
		}
    }
}