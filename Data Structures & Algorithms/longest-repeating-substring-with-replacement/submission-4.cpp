class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> window;
        int left = 0;
        int maxVal = 0;
        int maxLength = 0;
        for(int right = 0; right < (int)s.size(); ++right)
        {
            window[s[right]]++;

            maxVal = max(maxVal, window[s[right]]);

            while((right - left + 1) - maxVal > k)
            {
                window[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }
    
        return maxLength;
    }
};
