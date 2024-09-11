#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct Coord {
    int x, y;
};

int dirX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dirY[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    int caseNumber = 0;

    while (true) {
        int H, W;
        cin >> H >> W;

        if (H == 0 && W == 0)
            break;

        vector<Coord> starts;
        char grid[52][52]; 
        bool visited[52][52] = {false};

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'A')
                    starts.push_back({j, i});
            }
        }

        int maxPath = 0;
        queue<Coord> q;

        for (auto start : starts) {
            q.push(start);
            visited[start.y][start.x] = true;

            while (!q.empty()) {
                Coord curr = q.front();
                q.pop();
                maxPath = max(maxPath, grid[curr.y][curr.x] - 'A' + 1);

                for (int i = 0; i < 8; i++) {
                    int nx = curr.x + dirX[i];
                    int ny = curr.y + dirY[i];

                    if (nx >= 0 && nx < W && ny >= 0 && ny < H && 
                        !visited[ny][nx] && grid[ny][nx] == grid[curr.y][curr.x] + 1) {
                        q.push({nx, ny});
                        visited[ny][nx] = true;
                    }
                }
            }
        }

        cout << "Case " << ++caseNumber << ": " << maxPath << endl;
    }

    return 0;
}