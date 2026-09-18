class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        // 1. Find ALL treasures and put them in the queue as our starting points
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // 2. Flood outward from all treasures simultaneously
        while (!q.empty()) {
            pair<int, int> current = q.front();
            int r = current.first;
            int c = current.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];

                // If out of bounds, or NOT an empty room, skip it
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] != INT_MAX) {
                    continue;
                }

                // Because we flood outwards, the distance is simply the previous cell's distance + 1
                grid[nr][nc] = grid[r][c] + 1;
                
                // Push this newly discovered room into the queue to keep flooding outward from it
                q.push({nr, nc});
            }
        }
    }
};