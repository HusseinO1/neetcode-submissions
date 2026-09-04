#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";
        
        for (char c : s) {
            if (isalnum(c)) {
                clean += tolower(c);
            }
        }
        for(int i = 0; i < clean.size() / 2; i++)
        {
            if(clean[i] != clean[clean.size() - i - 1])
                return false;
        }
        return true;
    }
};