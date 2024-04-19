class Solution {
public:

    void dfs(vector<vector<int>> &adj, int i, int destination, vector<bool> &is_vis, bool &ans)
    {
        is_vis[i] = true;

        if(i == destination) {
            ans = true;
            return;
        }

        for(int j = 0; j < adj[i].size(); j++) {
            int x = adj[i][j];

            if(is_vis[x] == false) {
                dfs(adj, x, destination, is_vis, ans);              
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        bool ans = false;
        vector<vector<int>> adj(n);
        vector<bool> is_vis(n, false);

        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(adj, source, destination, is_vis, ans);
        return ans;
    }
};