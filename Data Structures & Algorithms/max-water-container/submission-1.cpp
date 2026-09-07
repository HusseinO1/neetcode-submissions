class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = -1;
        while(left < right)
        {
            int area = (right - left) * min(heights[left], heights[right]);

            if(area > maxArea)
                maxArea = area;
            
            if(heights[left] > heights[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return maxArea;
    }
};
