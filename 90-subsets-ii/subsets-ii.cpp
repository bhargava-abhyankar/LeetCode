class Solution {
public:
     
    /* This problem is same as leetcode problem number 77.Combinations 
       In that problem k or combination length is given, to find the subset
       of given array, combination for all combination length from 0 to array size 
       need to be calculated.  Since the duplicate elements are present, first sort
       the given array and then find sum. to avoid duplicate, added a check in 
       computation, if duplicate skip. */

    void combination(vector<int>& nums, int cur, vector<int> &cur_ans, vector<vector<int>> &ans, int k)
    {
        if(k == cur_ans.size()) {
            ans.push_back(cur_ans);
            return;
        }

        for(int i = cur; i < nums.size(); i++) {
            
            /* If duplicate then continue */
            if(i > cur && nums[i] == nums[i -1]) {
                continue;
            }

            cur_ans.push_back(nums[i]);
            combination(nums, i+1, cur_ans, ans, k);
            cur_ans.pop_back();    
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<int> cur_ans;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());         /* sort the array so that duplicates are adjacent */

        for(int i = 0; i <= nums.size(); i++) {
            combination(nums, 0, cur_ans, ans, i);
        }

        return ans;
    }
};