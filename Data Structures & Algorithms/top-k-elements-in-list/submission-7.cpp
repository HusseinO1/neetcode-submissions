class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto& num : nums) {
            m[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for(auto& p : m) {
            bucket[p.second].push_back(p.first);
        }
        
        vector<int> ans;
        
        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        
        return ans;
    }
};