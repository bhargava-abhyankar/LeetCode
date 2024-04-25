class Solution {
public:

    void dfs(vector<vector<pair<int, int>>> &adj, int i, vector<bool> &is_vis, int &result)
    {
        is_vis[i] = true;

        for(int j = 0; j < adj[i].size(); j++) {
            pair<int, int> p = adj[i][j];
            result = min(result, p.second);

            if(is_vis[p.first] == false) {
                dfs(adj, p.first, is_vis, result);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) 
    {
        int result = INT_MAX;
        vector<bool> is_vis(n, false);
        vector<vector<pair<int, int>>> adj(n+1);

        for(int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        dfs(adj, 1, is_vis, result);
        return result;
    }
};