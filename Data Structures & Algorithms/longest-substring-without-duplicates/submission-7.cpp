#include<string>
#include<vector>
class Solution {
public:

int lengthOfLongestSubstring(std::string& s) 
{
	std::vector<bool> seen(128, 0);
	int maxSize = 0;
	int left = 0;

	for(int right = 0; right < (int) s.size(); ++right)
	{
		if(seen[s[right]])
		{
			while(s[left] != s[right])
            {
                seen[s[left]] = false;
                left++;
            }
			left++;
		}
		seen[s[right]] = true;
		maxSize = max(maxSize, right - left + 1);
	}
	return maxSize;
}

};
