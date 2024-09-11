#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n, m, cnt;
int head[N];
int indegree[N];

struct Edge {
    int to, next;
} edges[M];

void add_edge(int a, int b) {
    edges[++cnt].to = b;
    edges[cnt].next = head[a];
    head[a] = cnt;
}

int queue[N], head_index = 0, tail_index = -1;

void topological_sort() {
    while (head_index <= tail_index) {
        int u = queue[head_index++];
        for (int i = head[u]; i; i = edges[i].next) {
            int v = edges[i].to;
            indegree[v]--;
            if (indegree[v] == 0) {
                queue[++tail_index] = v;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        indegree[v]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            queue[++tail_index] = i;
        }
    }

    topological_sort();

    if (tail_index < n - 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
