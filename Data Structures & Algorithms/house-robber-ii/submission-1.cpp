class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        return max(calculate(0, nums.size() - 1, nums), calculate(1, nums.size(), nums));

    }
    
    int calculate(int start, int end, vector<int>& nums)
    {
        int prev = 0;
        int prevprev = 0;

        for(int i = start; i < end; ++i)
        {
            int temp = prev;
            prev = max(prev, prevprev + nums[i]);
            prevprev = temp;
        }

        return prev;
    }
};
