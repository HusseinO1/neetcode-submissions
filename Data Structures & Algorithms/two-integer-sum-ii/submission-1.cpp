class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        while(left <= right)
        {
            auto it = numbers[left] + numbers[right];
            if(it < target)
            {
                left++;
            }
            else if(it > target)
            {
                right--;
            }
            else
            {
                return {left + 1, right + 1};
            }
        }

        return {};
    }
};
