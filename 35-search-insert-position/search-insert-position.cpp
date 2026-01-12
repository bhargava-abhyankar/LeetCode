class Solution {
public:

    /*
    void binary_search(vector<int>&nums, int left, int right, int target, int &ans)
    {
        if(left > right) {
            ans = left;
            return;
        }

        int mid = (left + right)/2;
        
        if(nums[mid] == target) {
            ans = mid;
            return;
        } else if (nums[mid] > target) {
            binary_search(nums, left, mid-1, target, ans);
        } else if (nums[mid] < target) {
            binary_search(nums, mid+1, right, target, ans);
        }

    }

    int searchInsert(vector<int>& nums, int target) 
    {
        int ans = 0, size = nums.size()-1 ;
        if(target < nums[0])
            ans = 0;
        else if (target > nums[size])
            ans = size + 1;
        else 
            binary_search(nums, 0, size, target, ans);
    
        return ans;
    }
    */

    /* lower bound approach 

    int searchInsert(vector<int>& nums, int target) 
    {
        int ans = nums.size();
        int start = 0, end = nums.size()-1;

        if(target < nums[0]) {
            return 0;
        }

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

    */


    int searchInsert(vector<int>& nums, int target) 
    {
        int start = 0, end = nums.size()-1;

        while(start <= end) {
            int mid = start + (end - start)/2;

            if(target == nums[mid]) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid -1;
            }
        }

        return start;
    }
};