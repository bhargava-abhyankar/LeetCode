class Solution {
public:

    /*Not adding duplicate check as duplicates are also part of ans. */

    void two_sum(vector<int>& nums, int cur, int index, int target, int &ans)
    {
        int i = index, j = nums.size()-1;

        while(i < j) {
            int sum = cur + nums[i] + nums[j];

            if(sum < target) {
                ans = ans + j - i;                   // note this. if sum is less than target, what ever in between is also will lead less only. because array is sorted
                i++;
            } else if (sum >= target) {
                j--;
            }
        }
    }

    int threeSumSmaller(vector<int>& nums, int target) 
    {
        int ans = 0;
        if(nums.size() < 3) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-2; i++) {
            two_sum(nums, nums[i], i+1, target, ans);
        }

        return ans;
    }
};