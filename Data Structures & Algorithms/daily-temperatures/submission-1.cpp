#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> decrease; 

        for (int i = n - 1; i >= 0; --i) {
            while (!decrease.empty() && temperatures[decrease.top()] <= temperatures[i]) {
                decrease.pop();
            }

            if (!decrease.empty()) {
                ans[i] = decrease.top() - i;
            }

            decrease.push(i);
        }

        return ans;
    }
};