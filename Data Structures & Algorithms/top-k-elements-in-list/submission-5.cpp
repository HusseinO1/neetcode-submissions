#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        for (const auto& num : nums) {
            seen[num]++;
        }

        vector<pair<int, int>> ans;

        for (const auto& p : seen) {
            if (ans.size() == k) {
                auto min_it = min_element(ans.begin(), ans.end(), 
                    [](const auto& a, const auto& b) {
                        return a.second < b.second;
                    });

                if (p.second > min_it->second) {
                    *min_it = p;
                }
            } else {
                ans.push_back(p);
            }
        }

        // Extract just the numbers
        vector<int> result;
        result.reserve(k);
        for (const auto& p : ans) {
            result.push_back(p.first);
        }

        return result;
    }
};