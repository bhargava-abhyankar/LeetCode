class Solution {
public:

    bool check(vector<int>& nums) 
    {
        int count = 0, n = nums.size() -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[i+1]) {
                count++;
                if(count > 1)
                    return false;
            }
        }

        if(count != 0 && nums[n] > nums[0]) /* condtion not required if no rotation found. i.e array is fully sorted */
            return false;

        return true;
    }

    /* Explanation :
       The solution will be O(n) only. 
       
       If the array is sorted, or sorted and rotated, at max you will find one descrepency in ascending order. 
       Count the descrepency by looping and if it exceeds 1, its not sorted rotated. Also if it rotated, then
       last element in the array should be less than the first element in the array. i.e after first descrepency
       all the elements should be smaller than the smallest element (first element) in first half. 
    */

};