class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        size_t left = 0;
        size_t right = (size_t)heights.size() - 1;
        int64_t maxArea = 0;

        while(left < right)
        {
            int64_t smallestWall = min(heights[left], heights[right]);
            int64_t area = (right - left) * smallestWall;

            maxArea = max(maxArea, area);

            if(heights [left] < heights[right])
                left++;
            else
                right--;
        }

        return maxArea;
    }
};
