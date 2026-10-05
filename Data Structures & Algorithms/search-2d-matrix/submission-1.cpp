class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;

        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            if(matrix[middle / n][middle % n] == target) return true;
            else if(matrix[middle / n][middle % n] < target) left = middle + 1;
            else right = middle - 1;
        }

        return false;
    }
};
