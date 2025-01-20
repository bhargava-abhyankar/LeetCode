class Solution {
public:

    /*
    int maxProfit(vector<int>& prices) 
    {
        
        int min_price = INT_MAX;
        int max_profit = 0;

        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < min_price) {
                min_price = prices[i];
            } else {
                max_profit = max_profit + (prices[i] - min_price);
                min_price =  prices[i];
            }
        }
        return max_profit;
    }

    */

    int maxProfit(vector<int>& prices) 
    {
        int max_profit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1])
                max_profit = max_profit + prices[i] - prices[i-1];
        }

        return max_profit;
    }
};