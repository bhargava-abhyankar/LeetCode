class Solution {
public:


    /* Method 1: Brute force */

    int findTheWinner(int n, int k) 
    {
        vector<int> nums;

        for(int i = 1; i <=n; i++) {
            nums.push_back(i);
        }

        int cur = 0;

        while(nums.size() > 1) {
            int index = (cur + k -1) % nums.size();
            nums.erase(nums.begin() + index);
            cur = index;
        }

        return nums[0];
    }
};