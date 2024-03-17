class Solution {
public:

    void dfs(vector<vector<int>>& isConnected, vector<bool> &is_vis, int i)
    {
        is_vis[i] = true;
        
        for(int j = 0; j < isConnected[i].size(); j++) {
            if(isConnected[i][j] && is_vis[j] == false) {
                dfs(isConnected, is_vis, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int count = 0;
        int n = isConnected.size();
        vector<bool> is_vis(n, false);

        for(int i = 0; i < isConnected.size(); i++) {
            if(is_vis[i] == false) {
                dfs(isConnected, is_vis, i);
                count++;
            }
        }

        return count;
    }
};