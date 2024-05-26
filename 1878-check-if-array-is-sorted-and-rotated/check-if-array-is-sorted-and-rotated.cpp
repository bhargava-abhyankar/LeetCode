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

        if(count != 0 && nums[n] > nums[0])
            return false;

        return true;
    }

};