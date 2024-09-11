#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

vector<long long> min_costs(int from, const vector<vector<pair<int, int>>> &neighbors) {
    vector<long long> min_costs(neighbors.size(), LLONG_MAX);
    min_costs[from] = 0;
    priority_queue<pair<long long, int>> frontier;
    frontier.push({0, from});
    while (!frontier.empty()) {
        auto [curr_cost, curr] = frontier.top();
        frontier.pop();
        if (-curr_cost != min_costs[curr]) continue;

        for (auto [n, nc] : neighbors[curr]) {
            long long new_cost = min_costs[curr] + nc;
            if (new_cost < min_costs[n]) {
                min_costs[n] = new_cost;
                frontier.push({-new_cost, n});
            }
        }
    }
    return min_costs;
}

int main() {
    int city_num, flight_num;
    cin >> city_num >> flight_num;
    vector<vector<pair<int, int>>> neighbors(city_num), reverse_neighbors(city_num);
    for (int f = 0; f < flight_num; f++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        neighbors[--from].emplace_back(--to, cost);
        reverse_neighbors[to].emplace_back(from, cost);
    }

    vector<long long> start_costs = min_costs(0, neighbors);
    vector<long long> end_costs = min_costs(city_num - 1, reverse_neighbors);
    long long total_min = LLONG_MAX;

    for (int c = 0; c < city_num; c++) {
        for (auto [n, nc] : neighbors[c]) {
            if (start_costs[c] == LLONG_MAX || end_costs[n] == LLONG_MAX) continue;
            total_min = min(total_min, start_costs[c] + (nc / 2) + end_costs[n]);
        }
    }
    cout << total_min << endl;
}
