class Solution {
public:

    /* first time approach

    int findMin(vector<int>& nums) 
    {
        int ans = INT_MAX;
        int start = 0, end = nums.size()-1;

        while(start <= end) {
            int mid = (start + end) / 2 ;

            if(nums[start] <= nums[mid]) {     //first part is sorted
                ans = min(ans, nums[start]);
                start = mid + 1;
            }
            else {                              // second part is sorted
                ans = min(ans, nums[mid]); 
                end = mid;
            }
        }

        return ans;
    }
    */

    /* optimization */

    int findMin(vector<int>& nums) 
    {
        int ans = INT_MAX;
        int start = 0, end = nums.size()-1;

        while(start <= end) {
            int mid = (start + end) / 2;

            if(nums[start] <= nums[end]) {
                ans = min(ans, nums[start]);
                break;
            }
            if(nums[start] <= nums[mid]) {
                ans = min(ans, nums[start]);
                start = mid + 1;
            } else {
                ans = min(ans, nums[mid]);
                end = mid - 1;
            }
        }

        return ans;
    }

    /* Important Note :
       Q. Find how many times the sorted array has been rotated.
       A. Find the min element in sorted rotated array. Its index will be number of times array has been rotated 
     */

};