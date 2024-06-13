class Solution {
public:
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
};