class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        
        int prev2 = 0;
        int prev1 = 1;
        int current;
        
        for(int i = 1; i <= n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return current;
    }
};