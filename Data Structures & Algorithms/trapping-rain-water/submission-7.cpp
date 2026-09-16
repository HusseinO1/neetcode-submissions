class Solution {
public:
    int trap(vector<int>& heights) {
        if (heights.size() < 3) return 0;

        int l = 0;
        int r = heights.size() - 1;
        
        int maxLeft = heights[l];
        int maxRight = heights[r];
        
        int totalWater = 0;

        while (l < r) {
            if (maxLeft < maxRight) {
                l++;
                maxLeft = max(maxLeft, heights[l]); 
                totalWater += maxLeft - heights[l]; 
            } 
            else {
                r--;
                maxRight = max(maxRight, heights[r]);
                totalWater += maxRight - heights[r];
            }
        }

        return totalWater;
    }
};