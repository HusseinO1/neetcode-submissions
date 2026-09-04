class Solution {
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> m;

        for(auto& c : s)
        {
            m[c]++;
        }

        for(auto c : t)
        {
            m[c]--;
        }

        for(pair<char, int> p : m)
        {
            if(p.second != 0)
                return false;
        }
        return true;
    }
};