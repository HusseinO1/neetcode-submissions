class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};

        int m = heights.size();
        int n = heights[0].size();
        
        // Fix 1: Use 2D bool vectors instead of unordered_set for fast, compile-safe lookups
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int, int>> pQ;
        queue<pair<int, int>> aQ;

        // Populate left/right borders
        for (int i = 0; i < m; ++i) {
            pacific[i][0] = true;
            pQ.push({i, 0});      // Fix 2: Use push() instead of insert()
            
            atlantic[i][n - 1] = true;
            aQ.push({i, n - 1});  // Fix 3: Use n-1 instead of an uninitialized row variable
        }

        // Populate top/bottom borders
        for (int j = 0; j < n; ++j) {
            pacific[0][j] = true;
            pQ.push({0, j});
            
            atlantic[m - 1][j] = true;
            aQ.push({m - 1, j});
        }

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Helper function to run BFS to avoid writing the loop twice
        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& reachable) {
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& d : dirs) {
                    int nr = r + d.first;
                    int nc = c + d.second; // Fix 4: Use .second for the column

                    // Fix 5: Bounds check must use >= for the maximum sizes
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if (!reachable[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                            reachable[nr][nc] = true;
                            q.push({nr, nc}); // Fix 6: Fixed comma typo
                        }
                    }
                }
            }
        };

        // Run BFS for both oceans
        bfs(pQ, pacific);
        bfs(aQ, atlantic);

        // Fix 7: Iterate through the grid at the end to find the intersections safely
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};