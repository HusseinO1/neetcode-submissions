class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int rows = board.size();
        int cols = board[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i = 0; i < rows; ++i)
        {
            if(board[i][0] == 'O') q.push({i, 0});
            if(board[i][cols - 1] == 'O') q.push({i, cols - 1});
        }

        for(int i = 0; i < cols; ++i)
        {
            if(board[0][i] == 'O') q.push({0, i});
            if(board[rows - 1][i] == 'O') q.push({rows - 1, i});
        }

        while(!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            board[curr.first][curr.second] = 'S';
            for(auto& dir : dirs)
            {
                int nr = curr.first + dir.first;
                int nc = curr.second + dir.second;

                if(nr < 0 || nc < 0 || nr >= rows || nc >= cols || board[nr][nc] != 'O') continue;

                q.push({nr, nc});
            }
        }

        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
};
