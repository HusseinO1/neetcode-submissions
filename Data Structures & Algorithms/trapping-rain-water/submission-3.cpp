class Solution {
public:
    int trap(vector<int>& heights)
    {
        vector<int> leftWalls = {0};

        vector<int> rightWalls = {0};

        int totalWater = 0;

        for(int i = 1; i < heights.size(); i++)
        {
            leftWalls.push_back(max(leftWalls.back(), heights[i - 1]));
            rightWalls.push_back(max(rightWalls.back(), heights[heights.size() - i]));
        }

        for(int i = 0; i < leftWalls.size(); i++)
        {
            totalWater += max(min(leftWalls[i], rightWalls[rightWalls.size() - i - 1]) - heights[i], 0);
        }

        return totalWater;
    }
};
