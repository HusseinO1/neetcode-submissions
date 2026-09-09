#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int midpoint = left + (right - left) / 2;
            int val = matrix[midpoint / n][midpoint % n];

            if (val == target) {
                return true;
            } else if (val < target) {
                left = midpoint + 1;
            } else {
                right = midpoint - 1;
            }
        }

        return false;
    }
};