class Solution {
public:

    void dfs(vector<vector<pair<int, int>>> &adj, int i, vector<bool> &is_vis, int &res)
    {
        is_vis[i] = true;

        for(int j = 0; j < adj[i].size(); j++) {
            pair<int, int> x = adj[i][j];
            int v = x.first;

            if(is_vis[v] == false) {
                if(x.second == 1) {
                    res++;
                }
                dfs(adj, x.first, is_vis, res);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) 
    {
        int res = 0;
        vector<bool> is_vis(n, false);
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back({connections[i][1], 1});
            adj[connections[i][1]].push_back({connections[i][0], -1});
        }

        dfs(adj, 0 , is_vis, res);

        return res;
    }
};