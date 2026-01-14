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
        int i = 0, j = 0;
        vector<int> ans;

        while(j < nums.size() && nums[j] <= 0) {
            j++;
        }
        i = j -1;
        
        while(i >= 0 && j < nums.size()) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];

            if(a < b) {
                ans.push_back(a);
                i--;
            }
            else {
                ans.push_back(b);
                j++;
            }
        }

        while(i >= 0) {
            ans.push_back(nums[i] * nums[i]);
            i--;
        }

        while(j < nums.size()) {
            ans.push_back(nums[j] * nums[j]);
            j++;
        }

        return ans;

    }
};