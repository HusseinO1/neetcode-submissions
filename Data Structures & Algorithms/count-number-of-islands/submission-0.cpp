class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int numIslands = 0;
        for(int row = 0; row < grid.size(); ++row)
        {
            for(int column = 0; column < grid[0].size(); ++column)
            {
                if(visited[row][column]) continue;
                if(grid[row][column] == '1')
                {
                    dFS(grid, visited, row, column);
                    numIslands++;
                }
                else visited[row][column] = true;
            }
        }
        return numIslands;
    }

    void dFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int column)
{
    visited[row][column] = true;

    if(grid[row][column] == '1')
    {
        if(row > 0 && !visited[row - 1][column])
        {
            dFS(grid, visited, row - 1, column);
        }
        if(row + 1 < grid.size() && !visited[row + 1][column])
        {
            dFS(grid, visited, row + 1, column);
        }
        if(column > 0 && !visited[row][column - 1])
        {
            dFS(grid, visited, row, column - 1);
        }
        if(column + 1 < grid[0].size() && !visited[row][column + 1])
        {
            dFS(grid, visited, row, column + 1);
        }
    }
}
};
