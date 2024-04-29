class Solution {
public:

    void dfs(vector<vector<int>> &adj, int i, vector<int> &color_map, bool input_color, bool &is_bipartite)
    {
        if(color_map[i] == -1) {
            color_map[i] = input_color;
        }

        for(int j = 0; j < adj[i].size(); j++) {
            int x = adj[i][j];

            if(color_map[x] == -1) {
                dfs(adj, x, color_map, !input_color, is_bipartite);
            }
            else if(color_map[x] == color_map[i]) {
                is_bipartite = false;    
            }
        }
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        bool is_bipartite = true;
        vector<vector<int>> adj(n+1);
        vector<int> color_map(n +1, -1);

        for(int i = 0; i < dislikes.size(); i++) {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        for(int i = 1; i <=n ; i++) {
            if(color_map[i] == -1) {
                dfs(adj, i, color_map, 0, is_bipartite);
            }
        }

        return is_bipartite;
    }
};