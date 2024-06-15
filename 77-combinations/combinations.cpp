class Solution {
public:

    void backtrack(int cur, vector<int> &cur_ans, vector<vector<int>> &ans, int n, int k)
    {
        if(k == cur_ans.size()) {
            ans.push_back(cur_ans);
            return;
        }

        for(int i = cur; i <=n; i++) {
            cur_ans.push_back(i);
            backtrack(i+1, cur_ans, ans, n, k);
            cur_ans.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> cur;
        vector<vector<int>> ans;

        backtrack(1, cur, ans, n, k);
        return ans;
    }
};