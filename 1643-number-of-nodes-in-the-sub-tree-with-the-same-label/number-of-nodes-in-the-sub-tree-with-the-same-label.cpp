class Solution {
public:

    void print_vector(vector<int> p)
    {
        for(int i = 0; i < p.size(); i++) {
            cout << p[i] << ", ";
        }
        cout<<endl;
    }

    vector<int> dfs(vector<vector<int>> &adj, int i, int parent, string &labels, vector<int> &ans)
    {
        vector<int> my_status(26, 0);
        vector<int> res_from_child(26, 0);
        char mylabel = labels[i];
        my_status[mylabel - 'a'] = 1;

        for(int j = 0; j < adj[i].size(); j++) {
            int x = adj[i][j];

            if(x == parent) {
                continue;
            }

            res_from_child = dfs(adj, x, i, labels, ans);
                      
            for(int k = 0; k < res_from_child.size(); k++) {
                my_status[k] = my_status[k] + res_from_child[k]; 
            }
        }

        ans[i] = my_status[mylabel - 'a'];
        return my_status;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        vector<int> ans(n);
        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(adj, 0, -1, labels, ans);
        return ans;
    }
};