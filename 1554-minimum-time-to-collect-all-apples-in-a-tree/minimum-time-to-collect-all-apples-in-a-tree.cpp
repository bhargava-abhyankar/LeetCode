class Solution {
public:

    int dfs(vector<vector<int>> &adj, int i, int parent, vector<bool>& hasApple)
    {        
        int time = 0;

        for(int j = 0; j < adj[i].size(); j++) {
            int x = adj[i][j];

            if(x == parent)
                continue;

            int time_from_child = dfs(adj, x, i, hasApple);

            if(time_from_child > 0 || hasApple[x] == true) {
                time = time + time_from_child + 2;
            }
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<vector<int>> adj(n);
        

        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = dfs(adj, 0, -1, hasApple);
        return ans;
    }

};