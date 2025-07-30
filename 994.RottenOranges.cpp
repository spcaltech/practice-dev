#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        std::queue<std::pair<int, int>> q;
        int fresh = 0;

        // Step 1: Count fresh oranges and queue rotten ones
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    ++fresh;
            }

        if (fresh == 0) return 0;

        int minutes = 0;
        std::vector<std::pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        // Step 2: BFS rot spreading
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front(); q.pop();

                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                        rotted = true;
                    }
                }
            }

            if (rotted) ++minutes;
        }

        return fresh == 0 ? minutes : -1;
    }
};
