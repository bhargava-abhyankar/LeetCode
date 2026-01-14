class Solution {
public:

    /*
    int singleNonDuplicate(vector<int>& nums) 
    {
        int start = 0, end = nums.size() - 1;

        while(start < end) {
            int mid = (start + end) / 2;

            if (( mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1] )){
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return nums[start];
    }

    */

    /* Logic explanation.
       This can be solved by leanear search or by xor the every element with the previos result. at last result will have single element. this takes o(n).
       To solve this in o(log n), use binary search. Idea/goal is to devide the array and find in which half the unique element is present. So we search
       only in half which has unique number

       Usual binary search, find mid.
       if mid is even, then it's duplicate should be in next index.
	   or if mid is odd, then it's duplicate  should be in previous index.
	   check these two conditions, if any of the conditions is satisfied,
	   then pattern is not missed, so check in next half of the array. i.e, left = mid + 1.

	   if condition is not satisfied, then the pattern is missed. so, single number must be before mid.
	   so, update end to mid. At last return the nums[left]

     */

    int singleNonDuplicate(vector<int>& nums) 
    {
        for(int i = 0; i < nums.size()-1; i = i+2) {
            if(nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }

        return nums.back();
    }
};