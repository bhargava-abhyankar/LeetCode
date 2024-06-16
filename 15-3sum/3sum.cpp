class Solution {
public:

    /* 3 sum problem is solved by fixing each element, and finding two sum in subsequent array.
       the while condition are to avoid duplicate ans. first sort the given array so two sum
       can be found using two pointer method. In case of two sum and here as well, i j will skip
       the duplicate element. 
       
       three sum = two_sum of x + y = -z */

    void find_two_sum(vector<int>& nums, int k, int target, vector<vector<int>> &ans)
    {
        int i = k, j = nums.size()-1;

        while(i < j) {
            
            if ((nums[i] + nums[j]) > target) {
                j--;
            } else if ((nums[i] + nums[j]) < target){
                i++;
            } else {
                ans.push_back({-target, nums[i], nums[j]});
                while(i < j && nums[i] == nums[i+1]) 
                    i++;
                while(i < j && nums[j] == nums[j-1]) 
                    j--;
                i++;
                j--; 
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;

        if(nums.size() < 3) {
            return ans;
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-2; i++) {
            if(i != 0 && nums[i] == nums[i-1]) {
                continue;
            }       
            find_two_sum(nums, i+1, -nums[i], ans);
        }

        return ans;
    }
};