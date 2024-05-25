class Solution {
public:

    /* method 1 */

    int lower_bound(vector<int>& nums, int target)
    {
        int ans = nums.size();
        int start = 0, end = nums.size()-1;

        while(start <= end) {
            int mid = (start + end)/2;
            
            if(nums[mid] >= target) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }

    int upper_bound(vector<int>& nums, int target)
    {
        int ans = nums.size();
        int start = 0, end = nums.size()-1;

        while(start <= end) {
            int mid = (start + end)/2;
            
            if(nums[mid] > target) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans(2, -1);

        if(nums.size() == 0)
            return ans;

        int low_bound = lower_bound(nums, target);
        int up_bound = upper_bound(nums, target);

        if(low_bound == nums.size() || nums[low_bound] != target) {
            return ans;
        } else {
            ans[0] = low_bound;
            ans[1] = up_bound-1;
        }

        return ans;
    }

    /*************************************************************************************************************************/

    /* Method 3: leetcode solution for reference */

    /*
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        auto low = lower_bound(nums.begin(),nums.end(),target);
        auto up = upper_bound(nums.begin(),nums.end(),target);
        
        if(low == nums.end() || *low != target)    return {-1,-1};
        
        int first = low - nums.begin();
        int last = up - nums.begin()-1;
        
        return {first ,last};
    }
    */

};