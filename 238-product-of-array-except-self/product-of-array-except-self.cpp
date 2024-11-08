class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> ans;
        int n = nums.size();
        double left_product[n], right_product[n];

        left_product[0] = 1; right_product[n-1] = 1;

        for(int i = 1; i < n; i++) {
            left_product[i] = left_product[i-1] * nums[i-1];
        }

        for(int i = n-2; i >= 0; i--) {
            right_product[i] = right_product[i+1] *nums[i+1];
        }

        for(int i = 0; i < nums.size(); i++) {
            ans.push_back(left_product[i] * right_product[i]);
        }

        return ans;
    }
};