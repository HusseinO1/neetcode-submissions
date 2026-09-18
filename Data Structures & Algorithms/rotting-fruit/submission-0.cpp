class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int mins = 0;
        queue<pair<int, int>> q;
        int totalFresh = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) totalFresh++;
                else if (grid[r][c] == 2) q.push({r, c});
            }
        }

        if (totalFresh == 0) return 0;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty() && totalFresh > 0) {
            int currentLevelSize = q.size();

            for (int k = 0; k < currentLevelSize; k++) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + directions[i][0];
                    int nc = c + directions[i][1];

                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] != 1) {
                        continue;
                    }

                    grid[nr][nc] = 2;
                    totalFresh--;
                    q.push({nr, nc});
                }
            }
            mins++;
        }

        return totalFresh == 0 ? mins : -1;
    }
};