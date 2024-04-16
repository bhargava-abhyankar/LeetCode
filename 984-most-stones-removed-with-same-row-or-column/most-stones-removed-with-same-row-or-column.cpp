class Solution {
public:
    void dfs(int i, vector<bool> &is_vis, vector<vector<int>>& stones)
    {
        is_vis[i] = true;
    
        for(int j = 0; j < stones.size(); j++) {
            int row = stones[j][0];
            int col = stones[j][1];

            if((stones[i][0] == row) || (stones[i][1] == col)) {
                if(is_vis[j] == false) {
                    dfs(j, is_vis, stones);
                }
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) 
    {
        int count = 0;
        int n = stones.size();
        vector<bool> is_vis(n, false);

        for(int i = 0; i < n; i++) {
            if(is_vis[i] == false) {
                dfs(i, is_vis, stones);
                count++;
            }
        }

        return (n - count);    
    }
};