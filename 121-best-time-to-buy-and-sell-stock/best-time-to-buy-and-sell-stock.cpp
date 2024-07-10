class Solution {
public:

    /*Initial intution was thought as sliding window. which is wrong.

    int maxProfit(vector<int>& prices) 
    {
        int sum = 0, i = 0, j = 0;

        while(i < prices.size()) {
            j = i + 1;
            while(j < prices.size() && prices[j] > prices[j-1]) {
                j++;
            }
            if (j-i-1 > 0) {
                sum = max(sum, (prices[j-1] - prices[i]));
            }
            i = j;
        }

        return sum;
    }

    */


    int maxProfit(vector<int>& prices) 
    {
        int sum = 0;
        int min_value = prices[0];
        int max_val = prices[0];

        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < min_value) {
                sum = (max(sum, (max_val - min_value)));
                min_value = prices[i];
                max_val = prices[i];
            } else if(prices[i] > max_val) {
                max_val = prices[i];
            }
        }

        return(max(sum, (max_val - min_value)));
    }
};