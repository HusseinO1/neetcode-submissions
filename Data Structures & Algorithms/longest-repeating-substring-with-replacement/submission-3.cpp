class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxSize = 0;
        int maxValInHash = 0;
        unordered_map<char, int> seen;

        for (int right = 0; right < (int)s.size(); ++right) {
            seen[s[right]]++;
            maxValInHash = max(maxValInHash, seen[s[right]]);
            if ((right - left + 1) - maxValInHash > k) {
                seen[s[left]]--;
                left++;
            }
            maxSize = max(maxSize, right - left + 1);
        }

        return maxSize;
    }
};