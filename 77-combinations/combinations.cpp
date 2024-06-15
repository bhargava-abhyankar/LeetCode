class Solution {
public:

    /*
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

    */


    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        backtrack(res,1,n,k,vector<int>());
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, int cur, int n, int k, vector<int>comb){
        if(k==0){
            res.push_back(comb);
            return;
        }
        // If cur>n-k, there are not enough numbers left, we have to select the current element

        if(cur<=n-k) backtrack(res,cur+1,n,k,comb);  
        comb.push_back(cur);
        backtrack(res,cur+1,n,k-1,comb);
    }

};