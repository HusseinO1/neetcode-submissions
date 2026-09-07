#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> done;
        vector<vector<string>> ans;

        for(auto& str : strs)
        {
            string s(26, 0);

            for(auto& c : str)
            {
                s[c - 'a']++;
            }

            done[s].push_back(str);
        }

        for(auto& p : done)
        {
            ans.push_back(p.second);
        }

        return ans;
    }
};