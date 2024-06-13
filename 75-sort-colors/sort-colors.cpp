class Solution {
public:

    /* This problem is called dutch flag problem, this is dutch flag algorithm. 
       In single pass, we can sort the element if only 3 type of elements are there
       idea is to fix the lower elements from 0 index till their count, the middle element
       to mid of array and high elements at end 
       
       note, the variballe mid the one which start from begining and eventually will land at 
       starting of middle elemets. high will end up at begining of high elements. 
       so the main while need to be run variable called mid */

    void swap(vector<int>& nums, int i , int j)
    {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    void sortColors(vector<int>& nums) 
    {
        int low = 0, mid = 0, high = nums.size()-1;

        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums, mid, low);
                mid++;
                low++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums, mid, high);
                high--;
            }
        }
    }

};