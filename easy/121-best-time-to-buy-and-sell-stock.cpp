class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        //sell pointer with buy pointer behind it, buy always goes to minimum
        int maxProfit = 0;
        int minBuyIndex = 0;

        for(int sellIndex = 1; sellIndex < prices.size(); sellIndex++)
        {
            if(prices[sellIndex] > maxProfit)
            {
                for(int buyIndex = minBuyIndex; buyIndex < sellIndex; buyIndex ++)
                {
                    if(prices[sellIndex] - prices[buyIndex] > maxProfit)
                    {
                        maxProfit = prices[sellIndex] - prices[buyIndex];
                        minBuyIndex = buyIndex;
                    }
                }
            }
            
        }

        return maxProfit;
    }
};