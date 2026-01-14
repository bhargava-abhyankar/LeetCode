class Solution {
public:
    /*
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> ans(n, 0);
        int i = 0, j = n-1, index = n-1;;

        while(i < j) {
            int x = nums[i] * nums[i];
            int y = nums[j] * nums[j];

            if(x > y) {
                ans[index] = x;
                index--;
                i++;        
            } else if (x < y) {
                ans[index] = y;
                index--;
                j--;
            } else {
                ans[index] = y;
                index--;
                ans[index] = x;
                index--;
                i++;
                j--;
            }
        }
        ans[0] = nums[i] * nums[i];
        return ans;
    }
    */

    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int i = 0, j = n-1, index = n-1;

        while(i <= j) {
            int x = abs(nums[i]) * abs(nums[i]);
            int y = abs(nums[j]) * abs(nums[j]);

            if(x > y) {
                ans[index] = x;
                index--;
                i++;
            } else {
                ans[index] = y;
                index--;
                j--;
            }
        }

        return ans;

    }
};