class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int maxArea = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) {
                    int area = 0;
                    dfs(grid, row, col, area);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }

private:
    void dfs(vector<vector<int>>& grid, int row, int col, int& area) {
        if (row < 0 || row >= grid.size() || 
            col < 0 || col >= grid[0].size() || 
            grid[row][col] == 0) {
            return;
        }
        area++;
        grid[row][col] = 0;
        dfs(grid, row - 1, col, area);
        dfs(grid, row + 1, col, area);
        dfs(grid, row, col - 1, area);
        dfs(grid, row, col + 1, area);
    }
};