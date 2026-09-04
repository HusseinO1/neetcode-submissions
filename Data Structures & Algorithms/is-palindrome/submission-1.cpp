class Solution {
public:
    bool isPalindrome(string s) {
        int back = s.size() - 1;
        int front = 0;

        while(front < back) {
            if (!isalnum(s[front])) {
                front++;
                continue;
            }
            if (!isalnum(s[back])) {
                back--;
                continue;
            }
            
            if (tolower(s[front]) != tolower(s[back]))
                return false;
                
            back--; 
            front++;
        }
        return true;
    }
};