class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        for(size_t i = 0; i < grid.size(); ++i)
        {
            for(size_t j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    maxSize = max(maxSize, DFS(i, j, grid));
                }
            }
        }
        return maxSize;
    }

    int DFS(int i, int j, vector<vector<int>>& grid)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return 0;
        
        grid[i][j] = 0;
        
        int currentSize = 1; 

        pair<int, int> directions[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        for(auto& dir : directions)
        {
            currentSize += DFS(dir.first + i, dir.second + j, grid); 
        }
        
        return currentSize;
    }
};
