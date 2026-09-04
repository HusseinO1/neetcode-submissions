class Solution {
public:
    bool isAnagram(string s, string t)
    {
        string f(26, 0);
        for(auto& c : s)
        {
            f[c - 'a']++;
        }
        for(auto& c : t)
        {
            f[c - 'a']--;
        }
        for(auto& c : f)
        {
            if(c != 0)
            {
                return false;
            }
        }
        return true;
    }
};
