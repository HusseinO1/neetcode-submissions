class Solution {
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> seen;

        for(auto& c : s)
        {
            seen[c]++;
        }

        for(auto& c : t)
        {
            seen[c]--;
        }

        for(auto& p : seen)
        {
            if(p.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};