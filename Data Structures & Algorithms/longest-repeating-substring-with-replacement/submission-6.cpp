class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxSize = 0;
        int maxNum = 0;
        vector<int> count(26, 0); // Replaced string with an int array/vector
        int left = 0;
        
        for (int right = 0; right < s.size(); right++) {
            // 1. Update counts and the historical max frequency
            count[s[right] - 'A']++;
            maxNum = max(maxNum, count[s[right] - 'A']);

            // 2. If the current window is invalid, slide the whole window to the right
            if ((right - left + 1) - maxNum > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            // 3. Unconditionally record the valid window size
            maxSize = max(maxSize, right - left + 1);
        }

        return maxSize;
    }
};