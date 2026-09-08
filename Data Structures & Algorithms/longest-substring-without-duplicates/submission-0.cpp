class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int longestSize = 0;
        unordered_map<char, int> seen;
        for(int right = 0; right < s.size(); right++)
        {
            char currentChar = s[right];
            if(seen.count(currentChar) && seen[currentChar] >= left)
            {
                left = seen[currentChar] + 1;
            }

            seen[currentChar] = right;

            longestSize = max(longestSize, right - left + 1);
        }
        return longestSize;
    }
};