class Solution {
public:

    /* This problem is same as leetcode problem number 77.Combinations 
       In that problem k or combination length is given, to find the subset
       of given array, combination for all combination length from 0 to array size 
       need to be calculated */

    void combination(vector<int>& nums, int cur, vector<int> &cur_ans, vector<vector<int>> &ans, int k)
    {
        if(k == cur_ans.size()) {
            ans.push_back(cur_ans);
            return;
        }

        for(int i = cur; i < nums.size(); i++) {
            cur_ans.push_back(nums[i]);
            combination(nums, i+1, cur_ans, ans, k);
            cur_ans.pop_back();    
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> cur_ans;
        vector<vector<int>> ans;

        for(int i = 0; i <= nums.size(); i++) {
            combination(nums, 0, cur_ans, ans, i);
        }

        return ans;
    }
};