class Solution {
public:

    /*Method 1: Cumulative Sum */

    double findMaxAverage(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<double> sum(n, 0);
        sum[0] = nums[0];

        for(int i = 1; i < n; i++) {
            sum[i] = nums[i] + sum[i-1];
        }
        double ans = (sum[k-1] * 1.0)/k;

        for(int i = k; i < n; i++) {
            ans = max(ans, ((sum[i] - sum[i-k]) * 1.0)/k);
        }

        return ans;
    }
};