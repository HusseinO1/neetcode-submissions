class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> seen;

        int left = 0;
        int maxVal = 0;
        int maxSize = 0;

        for(int right = 0; right < s.size() ; ++right)
        {
            seen[s[right]]++;
            maxVal = max(maxVal, seen[s[right]]);
            int currWinSize = right - left + 1;
            while(currWinSize - maxVal > k)
            {
                seen[s[left]]--;
                left++;
                currWinSize = right - left + 1;
            }

            maxSize = max(maxSize, currWinSize);
        }

        return maxSize;
    }
};
