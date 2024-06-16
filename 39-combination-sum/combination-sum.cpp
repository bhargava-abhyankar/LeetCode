class Solution {
public:

    /* The below code is first intution. code can find all the combinations with the duplicates. 
       Intial though was, find all combination of array till k = arry.size() and then do the sum
       of this and get whatever add to target.
       However, there is condition in question, The same number may be chosen from candidates an 
       unlimited number of times. Due to this, we dont know till what value of k we need to generate
       cobination. So this method cant be taken.
       But this code is very useful to find all combination of given array when it has duplicate elements
       with given k.
    */

    /*
    bool is_sum_same(vector<int>&cur_ans, int target)
    {
        int sum = 0;

        for(int i = 0; i < cur_ans.size(); i++) {
            sum = sum + cur_ans[i];
        }

        return( sum == target ? true:false);
    }

    void compute_combination(vector<int>& candidates, int cur, vector<int>&cur_ans,
                             vector<vector<int>> &ans,
                             int target, int k, bool &flag)
    {
        if(cur_ans.size() == k)
        {
            if(is_sum_same(cur_ans, target)) {
                ans.push_back(cur_ans);
            }
            return;
        }

        for(int i = cur; i < candidates.size(); i++) {
            cur_ans.push_back(candidates[i]);
            compute_combination(candidates, i, cur_ans, ans, target, k, flag);
            cur_ans.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> cur_ans;
        vector<vector<int>> ans;
        bool flag = false;

        for(int i = 0; i <= candidates.size(); i++) {
            compute_combination(candidates, 0, cur_ans, ans, target, i, flag);
        }

        return ans;
    }
    */

    void compute(vector<int>& candidates, int cur, vector<int>&cur_ans, vector<vector<int>>&ans, int target)
    {
        if(target == 0) {
            ans.push_back(cur_ans);
            return;
        } 
        if(target < 0) {
            return;
        }

        for(int i = cur; i < candidates.size(); i++) {
            cur_ans.push_back(candidates[i]);
            compute(candidates, i, cur_ans, ans, (target-candidates[i]));
            cur_ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> cur_ans;
        vector<vector<int>> ans;

        compute(candidates, 0, cur_ans, ans, target);
        return ans;
    }
}; 