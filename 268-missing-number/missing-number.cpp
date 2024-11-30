class Solution {
public:

    /* Method 1: Using formula

    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size(), actual_sum = 0;
        int expected_sum =  ((n + 1) * ((n+1) - 1))/ 2;

        for(int i = 0; i < n; i++) {
            actual_sum = nums[i] + actual_sum;
        }

        return expected_sum - actual_sum;

    }

    */

    /* Method 2: Using bitwise */

    int missingNumber(vector<int>& nums) 
    {
        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            ans = ans ^ (nums[i] ^ i);            
        }

        return ans;
    }

};