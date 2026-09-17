class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        int maxFreq = 0;
        
        for (char c : tasks) {
            count[c - 'A']++;
            maxFreq = max(maxFreq, count[c - 'A']);
        }

        int maxCount = 0;
        for (int freq : count) {
            if (freq == maxFreq) {
                maxCount++;
            }
        }

        int formulaSlots = (maxFreq - 1) * (n + 1) + maxCount;

        return max((int)tasks.size(), formulaSlots);
    }
};