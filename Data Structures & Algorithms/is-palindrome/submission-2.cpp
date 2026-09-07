class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        // Note: left < right is sufficient. When left == right, 
        // it's the middle character, which always equals itself.
        while (left < right) 
        {
            if (!isalnum(s[left])) 
            {
                left++; 
                continue;
            }
            if (!isalnum(s[right])) 
            {
                right--; 
                continue;
            }

            if (tolower(s[left]) != tolower(s[right])) 
            {
                return false;
            } 
            else 
            {
                left++; 
                right--;
            }
        }

        return true;
    }
};