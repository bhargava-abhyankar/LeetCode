class Solution {
public:

    /* Method 1: O(n) in worst case. Search a target. if found, traverse left and right
                 and count the target, if its more than n/2 then its mejority element
     */

    bool isMajorityElement(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int start = 0, end = n -1, count = 0;

        while(start <= end) {
            int mid = start + (end - start)/2;

            if(nums[mid] == target) {
                int i = mid;

                while(i >= 0 && nums[i] == target) {
                    count++;
                    i--;
                }
                
                while(mid < n && nums[mid] == target) {
                    count++;
                    mid++;
                }

                if((count-1) > (n/2))
                    return true;
                else 
                    return false;

            } else if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid -1;
            }
        }

        return false;
    }
};