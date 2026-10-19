class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxProfit = 0;
        int minPrice = prices[0];

        for(int sellIndex = 1; sellIndex < prices.size(); sellIndex++)
        {
            int profit = prices[sellIndex] - minPrice;

            maxProfit = max(maxProfit, profit);

            minPrice = min(minPrice, prices[sellIndex]);
        }

        return maxProfit;
    }
};