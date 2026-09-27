class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        for(size_t i = 0; i < grid.size(); ++i)
        {
            for(size_t j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    DFS(i, j, grid);
                    numIslands++;
                }
            }
        }
        return numIslands;
    }

    void DFS(int i, int j, vector<vector<char>>& grid)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
        
        grid[i][j] = '0';

        pair<int, int> directions[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        for(auto& dir : directions)
        {
            DFS(dir.first + i, dir.second + j, grid);
        }
    }
};
