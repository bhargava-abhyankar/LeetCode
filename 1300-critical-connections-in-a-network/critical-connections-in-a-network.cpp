class Solution {
public:
    int time = 1;

    void dfs(vector<vector<int>> &adj, int i, int parent, vector<bool> &is_vis, vector<vector<int>> &ans, vector<int> &time_ins, vector<int> &low_time)
    {
        is_vis[i] = true;
        time_ins[i] = low_time[i] = time;
        time++;

        for(int j = 0; j < adj[i].size(); j++) {
            int x = adj[i][j];

            if(x == parent) {
                continue;
            }

            if(is_vis[x] == false) {

                dfs(adj, x, i, is_vis, ans, time_ins, low_time);

                low_time[i] = min(low_time[i], low_time[x]);

                if(low_time[x] > time_ins[i]) {
                    ans.push_back({i, x}); 
                }
            }
            else {
                low_time[i] = min(low_time[i], low_time[x]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<bool> is_vis(n, 0);
        vector<int> time_ins(n, 0);
        vector<int> low_time(n, 0);
        vector<vector<int>> adj(n);
        vector<vector<int>> ans;

        for(auto it: connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }


        dfs(adj, 0, -1, is_vis, ans, time_ins, low_time);

        return ans;
    }
};