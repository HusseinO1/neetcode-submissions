class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> windowMaxes;
        windowMaxes.reserve(nums.size() - k + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>> window;
        for(int i = 0; i < k; ++i)
        {
            window.push({nums[i], i});
        }
        windowMaxes.push_back(window.top().first);
        for(int i = k; i < nums.size(); ++i)
        {
            window.push({nums[i], i});
            while(window.top().second <= i - k)
            {
                window.pop();
            }
            windowMaxes.push_back(window.top().first);
        }

        return windowMaxes;
    }
};
