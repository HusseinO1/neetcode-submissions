class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.end());

        while(q.size() > k)
        {
            q.pop();
        }

        return q.top();
    }
};
