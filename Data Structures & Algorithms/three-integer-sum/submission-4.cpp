class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto numsSize = nums.size();
        vector<vector<int>> threeSums;

        for(int i = 0; i <= numsSize - 3; ++i)
        {
            int left = i + 1;
            int right = numsSize - 1;

            if(i > 0 && nums[i - 1] == nums[i])
            {
                continue;
            }
            
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0)
                {
                    left++;
                }
                else if(sum > 0)
                {
                    right--;
                }
                else
                {
                    threeSums.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left + 1] == nums[left])
                    {
                        left++;
                    }
                    while(left < right && nums[right - 1] == nums[right])
                    {
                        right--;
                    }
                    
                    left++;
                    right--;
                }
            }
        }
        return threeSums;
    }
};