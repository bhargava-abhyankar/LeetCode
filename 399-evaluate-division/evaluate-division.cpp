class Solution {
public:

    void dfs(unordered_map<string, vector<pair<string, double>>> &adj, unordered_map<string, bool> &is_vis, vector<double> &ans, string cur, string dest, double res, bool &flag)
    {
        is_vis[cur] = true;

        if(cur == dest) {
            ans.push_back(res);
            flag = true;
            return;
        }

        for(int i = 0; i < adj[cur].size(); i++) {
            string x = adj[cur][i].first;
            double value = adj[cur][i].second;

            if(is_vis[x] == false) {
                dfs(adj, is_vis, ans, x , dest, res*value, flag);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        bool flag = false;
        vector<double> ans;
        unordered_map<string, vector<pair<string, double>>> adj;
        unordered_map<string, bool> is_vis;

        for(int i = 0; i < equations.size(); i++) {

            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            is_vis[equations[i][0]] = false;
            is_vis[equations[i][1]] = false;
        }

        for(int i = 0; i < queries.size(); i++)
        {
            if (adj.find(queries[i][0]) == adj.end() || adj.find(queries[i][1]) == adj.end()) {
                cout << queries[i][0] << " , " << queries[i][1] <<endl;
                ans.push_back(-1.0);
                continue;
            }

            dfs(adj, is_vis, ans, queries[i][0],queries[i][1], 1, flag);

            if (flag == false) {
                ans.push_back(-1.0);
            }
            is_vis.clear();
            flag = false;
        }

        return ans;
    }
};