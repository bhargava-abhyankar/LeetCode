class Solution {
public:

    void compute(vector<int>&nums, int cur, vector<int>&cur_ans, vector<vector<int>>&ans, vector<bool>&is_vis)
    {
        if(cur_ans.size() == nums.size()) {
            ans.push_back(cur_ans);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(is_vis[i] == false) { 
                is_vis[i] = true;
                cur_ans.push_back(nums[i]);
                compute(nums, i, cur_ans, ans, is_vis);
                cur_ans.pop_back();
                is_vis[i] = false;
            }
        }
        
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<bool> is_vis(nums.size(), false);
        vector<int> cur_ans;
        vector<vector<int>> ans;

        compute(nums, -1, cur_ans, ans, is_vis);
        return ans;

    }
};