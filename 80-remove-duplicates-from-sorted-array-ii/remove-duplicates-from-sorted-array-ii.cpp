class Solution {
public:
    /*
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size() < 3) {
            return nums.size();
        }

        int i = 2;

        for(int j = 2; j < nums.size(); j++) {
            if((nums[j] != nums[i-1]) || (nums[j] != nums[i-2]) ) {
                nums[i] = nums[j];
                i++;
            } 
        }
        return (i);
    }

    */

    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size() < 3) 
            return nums.size();
        
        int i = 1, j = 2;

        while(j < nums.size()) {
            if((nums[j] == nums[i]) && (nums[j] == nums[i-1])) {
                j++;
            } else {
                nums[i+1] = nums[j];
                i++;
                j++;
            }
        }
        return (i+1);
    }

};