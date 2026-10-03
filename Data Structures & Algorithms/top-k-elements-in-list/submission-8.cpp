class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
{
	unordered_map<int, int> m;

	for(size_t i = 0; i < nums.size(); ++i)
	{
		m[nums[i]]++;
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> kNums;

	for(pair<int, int> p : m)
	{
		kNums.push({p.second, p.first});
            if(kNums.size() > k)
{
    kNums.pop(); // Automatically kicks out the smallest frequency
}
	}
	
	vector<int> ans;

	while(!kNums.empty())
	{
		ans.push_back(kNums.top().second);
		kNums.pop();
	}
	
	return ans;
}

};
