#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        
        for (const auto& pair : counts) {
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result;
    }
};