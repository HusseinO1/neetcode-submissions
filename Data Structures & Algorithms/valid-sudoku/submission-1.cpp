#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.')
                    continue;
                
                string rx = "row - " + to_string(i) + " - " + board[i][j];
                string cy = "col - " + to_string(j) + " - " + board[i][j];
                string be = "box - " + to_string((i / 3) * 3 + (j / 3)) + " - " + board[i][j];
                
                if(!(seen.insert(rx).second && seen.insert(cy).second && seen.insert(be).second))
                {
                    return false;
                }
            }
        }
        return true;
    }
};