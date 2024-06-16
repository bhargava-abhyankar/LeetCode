class Solution {
public:

    /*
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
    */

    /*The approach is not very straight forward. For combination, based on recursive stack
      added elements to array. This is because combination is choosing k from n. 
      For permutation, its arranging n in different ways. ans will always have n 
      Idea s to swap each element with itself and others */

    void compute(vector<int>& nums, int cur, vector<vector<int>>&ans)
    {
        if(cur == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i = cur; i < nums.size(); i++) {
            swap(nums[i], nums[cur]);
            compute(nums, cur+1, ans);
            swap(nums[i], nums[cur]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        compute(nums, 0, ans);

        return ans;    
    }
};