class Solution {
public:
    /*
      my solution

    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int i = 0, j = 0;

        while(i < nums.size()) {
            if ((nums[i]%2) == 0) {
                i++;
            } else {
                break;
            }
        }

        j = i;

        while(j < nums.size()) {
            if((nums[j] % 2) == 1) {
                j++;
            } else {
                int t = nums[j];
                nums[j] = nums[i];
                nums[i] = t;
                i++;
                j++;
            }
        }

        return nums;
    }

    */

    /*From solution section */

    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        
        while (i < j) {
            while (i < j && nums[i] % 2 == 0)
                i++;
            while (i < j && nums[j] % 2 == 1)
                j--;
            
            swap(nums[i], nums[j]);
        }
        
        return nums;
    }
};