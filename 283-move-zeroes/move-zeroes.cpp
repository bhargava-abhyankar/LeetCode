class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int p1 = -1, p2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                p1 = i;
                p2 = i + 1;
                break;
            }
        }

        while(p1 != -1 && p2 < nums.size()) {
            if(nums[p2] != 0) {
                nums[p1] = nums[p2];
                nums[p2] = 0;
                p1++; 
            } else {
                p2++;
            }
        }
    }
};