class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int minutes = 0;
        int currLevelSize;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        while(!q.empty())
        {
            currLevelSize = q.size();
            for(int i = 0; i < currLevelSize; ++i)
            {
                auto currElement = q.front();
                q.pop();
                for(auto& dir : dirs)
                {
                    if(isValid({currElement.first + dir.first, currElement.second + dir.second}, grid))
                    {
                        grid[currElement.first + dir.first][currElement.second + dir.second] = 2;
                        q.push({currElement.first + dir.first, currElement.second + dir.second});
                    }
                }
            }
            if(!q.empty()) minutes++;
        }
        
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1) return -1;
            }
        }

        return minutes;
    }

    bool isValid(pair<int, int> p, const vector<vector<int>>& grid)
    {
        if(p.first < 0 || p.second < 0 || p.first >= grid.size() || p.second >= grid[0].size() || grid[p.first][p.second] != 1) return false;
        
        return true;
    }
};
