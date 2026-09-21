class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ans;
        for(auto& str : strs)
        {
            string s(26, 0);

            for(auto& c : str)
            {
                s[c - 'a']++;
            }

            m[s].push_back(str);
        }

        for(auto& p : m)
        {
            ans.push_back(p.second);
        }

        return ans;
    }
};
