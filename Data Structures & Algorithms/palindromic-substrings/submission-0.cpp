class Solution {
public:
    int countSubstrings(string s) {
        int num = 0;
        string ans;
        for(int i = 0; i < s.size(); ++i)
        {
            dfs(s, i, i, num);
            dfs(s, i, i+1, num);
        }
        return num;
    }

    void dfs(string& s, int left, int right, int& num)
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
            num++;
        }
    }
};
