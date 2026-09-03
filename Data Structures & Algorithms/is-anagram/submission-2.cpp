class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> place;
        
        for(char c: s) {
            place[c]++; 
        }

        for(char c: t) {
            if(place.contains(c)) {
                place[c]--;
            } else {
                return false;
            }
        }

        for (const auto& pair : place) {
            if (pair.second != 0) {
                return false;
            }
        }
        
        return true; 
    }
};