class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int numIslands(vector<vector<char>>& grid) {
        int nIslands = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    nIslands++;
                    AnalyzeIsland(i, j, grid);
                }
            }
        }
        return nIslands;
    }

    void AnalyzeIsland(int i, int j, vector<vector<char>>& grid)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;

        grid[i][j] = '0';

        for(auto& dir : dirs)
        {
            AnalyzeIsland(i + dir.first, j + dir.second, grid);
        }
    }
};
