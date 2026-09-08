class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // FIX 1: Prevent underflow if array is too small
        if (nums.size() < 3) return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int curr = 0; curr < nums.size() - 2; ++curr) {
            // FIX 2a: Skip duplicates for the current pivot number
            if (curr > 0 && nums[curr] == nums[curr - 1]) {
                continue;
            }

            int l = curr + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int64_t sum = (int64_t)nums[curr] + nums[l] + nums[r];

                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    // We found a valid triplet
                    ans.push_back({nums[curr], nums[l], nums[r]});
                    
                    // Move both pointers inward
                    l++; 
                    r--;

                    // FIX 2b: Skip duplicates for the left pointer
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    
                    // FIX 2c: Skip duplicates for the right pointer
                    while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};