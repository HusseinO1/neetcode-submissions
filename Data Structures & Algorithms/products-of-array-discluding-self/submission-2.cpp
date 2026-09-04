#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        vector<int> ans(nums.size());

        int l = 1;

        for(int i = 0; i < nums.size(); ++i)
        {
            ans[i] = l;
            l *= nums[i];
        }

        l = 1;

        for(int i = nums.size() - 1; i >= 0; --i)
        {
            ans[i] *= l;
            l *= nums[i];
        }

        return ans;
    }
};