class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        
        // 1. Initialize the first window of size s1.size()
        for (int i = 0; i < s1.size(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }
        
        // 2. Slide the window across the rest of s2
        for (int i = s1.size(); i < s2.size(); i++) {
            if (s1Count == s2Count) return true; // C++ vectors can be compared directly
            
            // Add the new character entering the window
            s2Count[s2[i] - 'a']++;
            // Remove the old character left behind by the window
            s2Count[s2[i - s1.size()] - 'a']--;
        }
        
        // 3. Check the very last window
        return s1Count == s2Count;
    }
};