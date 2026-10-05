class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = -67;
        for(size_t i = 0; i < piles.size(); ++i)
        {
            maxVal = max(maxVal, piles[i]);
        }

        int* right = &maxVal;

        int left = 1;


        while(left < *right)
        {
            int mid = left + (*right - left) / 2;

            uint64_t hours = 0;
            for(size_t i = 0; i < piles.size(); ++i)
            {
                hours += ceil((double)piles[i] / mid);
            }

            if(hours <= h)
            {
                *right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return *right;
    }
};
