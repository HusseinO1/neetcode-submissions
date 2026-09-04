class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ints;

        for(int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            
            if(ints.contains(difference)) {
                return {min(i, ints[difference]), max(i, ints[difference])};
            }
            
            ints[nums[i]] = i;
        }
        
        return {};
    }
};