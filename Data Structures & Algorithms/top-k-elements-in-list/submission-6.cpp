class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        // Use std::map (ordered) to automatically sort by frequency.
        // Map frequency to a vector of numbers to prevent overwriting.
        map<int, vector<int>> freqToNums; 
        vector<int> ans;

        for(int num : nums) {
            counts[num]++;
        }

        for(auto& p : counts) {
            freqToNums[p.second].push_back(p.first);
        }

        for (auto it = freqToNums.rbegin(); it != freqToNums.rend() && ans.size() < k; ++it) {
            for (int num : it->second) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }

        return ans;
    }
};