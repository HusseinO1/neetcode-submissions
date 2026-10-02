class Solution {
public:
    string longestPalindrome(string s) {
        int maxSize = 0;
        string ans;
        for(int i = 0; i < s.size(); ++i)
        {
            int odd = dfs(s, i, i);
            int even = dfs(s, i, i+1);
            
            int bigger = max(even, odd);

            if(bigger > maxSize)
            {
                maxSize = bigger;
                ans = s.substr(i - (maxSize - 1) / 2, maxSize);
            }
        }
        return ans;
    }

    int dfs(string& s, int left, int right)
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return right - left - 1;
    }
};
