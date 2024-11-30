class Solution {
public:

    /* Method 1: O(n) method 

    int missingElement(vector<int>& nums, int k) 
    {
        int n = nums.size();
        for(int i = 1; i < n; i++) {

            int gap = nums[i] - nums[i-1] - 1;

            if(gap >= k) {
                return nums[i-1] + k;
            }

            k = k - gap;
        }

        return nums[n-1] + k;
    }

    */

    /* Using binary search. O(log n). This binary search is tricky.  */

    int missingElement(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int start = 0, end = n-1;

        while(start < end) {
            int mid = end - (end - start) / 2;

            if(nums[mid] - nums[0] - mid < k) {
                start = mid;
            } else {
                end = mid -1;
            }
        }

        return nums[0] + k + start;
    }

};