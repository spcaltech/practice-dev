class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); if (!m) return 0;
        int n = grid[0].size(), cnt = 0;
        const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1') {
                    ++cnt;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        auto [r,c] = q.front(); q.pop();
                        for (auto d: dirs) {
                            int nr = r + d[0], nc = c + d[1];
                            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1') {
                                grid[nr][nc] = '0';
                                q.push({nr,nc});
                            }
                        }
                    }
                }
        return cnt;
    }
};
