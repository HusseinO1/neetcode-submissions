class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> iHateStacks;
        vector<int> ans(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++)
        {
            if(iHateStacks.empty()) iHateStacks.push(i);

            while(!iHateStacks.empty() && temperatures[iHateStacks.top()] < temperatures[i])
            {
                ans[iHateStacks.top()] = i - iHateStacks.top();
                iHateStacks.pop();
            }

            iHateStacks.push(i);
        }

        while(!iHateStacks.empty())
        {
            ans[iHateStacks.top()] = 0;
            iHateStacks.pop();
        }

        return ans;
    }
};
