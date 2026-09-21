class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs(nums.begin(), nums.end());
        int mx = 0;

        for (int num : hs) {
            if (!hs.contains(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (hs.contains(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }

                mx = max(mx, currentStreak);
            }
        }

        return mx;
    }
};