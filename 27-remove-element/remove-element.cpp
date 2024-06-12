class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int i = 0, j = 0;

        while(i < nums.size()) {
            if(nums[i] != val) {
                i++;
            } else {
                /*
                j = i;
                while(j < nums.size() && nums[j] != val) {
                    j++;
                }
                */
                break;
            }
        }
        j = i;
        while(j < nums.size()) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                nums[j] = val;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return (i);
    }
};