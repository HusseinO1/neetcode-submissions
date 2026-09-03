#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> groups;

    for (const string& s : strs)
    {
        string key(26, 0); 

        for (char c : s)
        {
            key[c - 'a']++; 
        }

        groups[key].push_back(s);
    }

        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(pair.second);
        }

        return result;
    }
};