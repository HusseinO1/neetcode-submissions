#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int k = s1.size();
        int n = s2.size();
        if (k > n) return false;

        std::vector<int> target(26, 0);
        std::vector<int> window(26, 0);

        for (char c : s1) {
            target[c - 'a']++;
        }

        for (int i = 0; i < k; ++i) {
            window[s2[i] - 'a']++;
        }

        if (window == target) return true;

        for (int right = k; right < n; ++right) {
            window[s2[right] - 'a']++;

            window[s2[right - k] - 'a']--;

            if (window == target) {
                return true;
            }
        }

        return false;
    }
};