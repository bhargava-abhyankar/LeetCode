class Solution {
public:

    /* Method 1: Brute force O(n2)

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

    */

    /* Method 2: Better solution */

    int findTheWinner(int n, int k) 
    {
        int ans = 0;

        for(int i = 2; i <=n; i++) {
            ans = (ans + k) % i;
        }

        // add 1 to convert back to 1 indexing
        return ans + 1;
    }
};