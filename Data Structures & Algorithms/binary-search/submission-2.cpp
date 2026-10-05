class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = (int)nums.size() - 1;

        while(left <= right)
        {
            int mp = left + (right - left) / 2;
            if(nums[mp] < target)
            {
                left = mp + 1;
            }
            else if(nums[mp] > target)
            {
                right = mp - 1;
            }
            else return mp;
        }
        return -1;
    }
};
