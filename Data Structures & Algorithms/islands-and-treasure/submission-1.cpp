class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i,j});
                }
            }
        }
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            pair<int, int> current = q.front();
            int r = current.first;
            int c = current.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] != INT_MAX) {
                    continue;
                }

                grid[nr][nc] = grid[r][c] + 1;
                
                q.push({nr, nc});
            }
        }
    }
};
