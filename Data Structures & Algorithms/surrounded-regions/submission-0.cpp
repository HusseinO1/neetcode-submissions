class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> safe(rows, vector<bool>(cols, false));

        queue<pair<int, int>> q;

        
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < cols; i++) 
{
    // Top border
    if (board[0][i] == 'O' && !safe[0][i]) 
    {
        safe[0][i] = true;
        q.push({0, i});
    }
    
    // Bottom border
    if (board[rows - 1][i] == 'O' && !safe[rows - 1][i]) 
    {
        safe[rows - 1][i] = true;
        q.push({rows - 1, i});
    }
}

for (int i = 0; i < rows; i++) 
{
    // Left border
    if (board[i][0] == 'O' && !safe[i][0]) 
    {
        safe[i][0] = true;
        q.push({i, 0});
    }
    
    // Right border (was incorrectly using rows - 1)
    if (board[i][cols - 1] == 'O' && !safe[i][cols - 1]) 
    {
        safe[i][cols - 1] = true;
        q.push({i, cols - 1});
    }
}

        while(!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();

            for (auto& d : dirs)
            {
                int nr = curr.first + d.first;
                int nc = curr.second + d.second;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
                {
                    if (board[nr][nc] == 'O' && !safe[nr][nc])
                    {
                        safe[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                if(board[i][j] == 'O' && !safe[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
