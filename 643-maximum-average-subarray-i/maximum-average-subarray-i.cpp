class Solution {
public:

    /* Method 1: Brute force 

    double findMaxAverage(vector<int>& nums, int k) 
    {
        double ans = INT_MIN;

        for(int i = 0; i <= nums.size()-k; i++) {
            double sum = 0;

            for(int j = i; j < i + k; j++) {
                sum = sum + nums[j];
            }

            ans = max(ans, sum/k);
        }

        return ans;
    }

    */

    /* Method 2: Cumulative Sum 

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

    */

    /* Method 3: Sliding Window */

    double findMaxAverage(vector<int>& nums, int k) 
    {
        double sum = 0;

        for(int i = 0; i < k; i++) {
            sum = sum + nums[i];
        }

        double max_sum = sum;

        for(int i = k; i < nums.size(); i++) {
            sum =  sum + nums[i] - nums[i-k];

            if(sum > max_sum)
                max_sum = sum;
        }

        return(max_sum/k);
    }

};