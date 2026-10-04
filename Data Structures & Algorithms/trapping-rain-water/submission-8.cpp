#include<vector>
#include<algorithm>
class Solution {
public:
int trap(vector<int>& height)
{
	int hSize = height.size();

	if(hSize < 3) return 0;

	int total = 0;

	int left = 0;
	int right = height.size() - 1;
	
	int leftMax = height[0];
	int rightMax = height[hSize - 1];

	while(left < right)
	{
		if(leftMax < rightMax)
		{
			left++;
			leftMax = max(leftMax, height[left]);
			total += leftMax - height[left];
		}
		else
		{
			right--;
			rightMax = max(rightMax, height[right]);
			total += rightMax - height[right];
		}
	}
	
	return total;
}

};
