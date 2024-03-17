class Solution {
public:

    void dfs(vector<vector<int>> &adj, vector<bool> &is_vis, int i)
    {
        is_vis[i] = true;

        for(int j = 0; j < adj[i].size(); j++) {
            if(is_vis[adj[i][j]] == false) {
                dfs(adj, is_vis, adj[i][j]);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int components = 0;
        vector<vector<int>> adj(n);
        vector<bool> is_vis(n, false);

        if(connections.size() < n-1) {
            return -1;
        }

        for(int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        for(int i = 0; i < n; i++) {
            if(is_vis[i] == false) {
                dfs(adj, is_vis, i);
                components++;
            }
        }

        return (components-1);
    }
};