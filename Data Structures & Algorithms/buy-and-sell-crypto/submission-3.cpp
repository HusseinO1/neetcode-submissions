class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int buyIn = 0;
        int sellOut = 1;
        int highestProfit = 0;

        while(sellOut < prices.size())
        {
            if(prices[sellOut] < prices[buyIn])
            {
                buyIn = sellOut;
                sellOut = buyIn + 1;
                continue;
            }
            else
            {
                if(prices[sellOut] - prices[buyIn] > highestProfit)
                {
                    highestProfit = prices[sellOut] - prices[buyIn];
                }

                sellOut++;
            }
        }
        return highestProfit;
    }
};
