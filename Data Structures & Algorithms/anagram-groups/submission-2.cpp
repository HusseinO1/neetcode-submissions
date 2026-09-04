#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (const auto& str : strs) {
            string seen(26, 0);
            for (char c : str) {
                seen[c - 'a']++;
            }
            m[seen].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& pair : m) {
            result.push_back(pair.second);
        }

        return result;
    }
};