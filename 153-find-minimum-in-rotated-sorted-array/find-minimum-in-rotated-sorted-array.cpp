class Solution {
public:
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
                //ans = min(ans, nums[mid + 1]); 
                //end = mid - 1;

                ans = min(ans, nums[mid]); 
                end = mid;
            }
        }

        return ans;
    }
};