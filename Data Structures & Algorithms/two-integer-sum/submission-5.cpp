#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        unordered_map<int, int> nms;

        for(int i = 0; i < nums.size(); ++i)
        {
            nms[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nms.contains(target - nums[i]) && i != nms[target - nums[i]])
            {
                return {min(nms[target - nums[i]], i), max(nms[target - nums[i]], i)};
            }
        }
    }
};