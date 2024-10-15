class Solution {
public:

    /* Method 1: Using DFS. kind of post order */

    vector<int> dfs(vector<vector<int>> &adj, int i, int parent, string &labels, vector<int> &ans)
    {
        vector<int> cur_node_counts(26);

        for(int j = 0; j < adj[i].size(); j++) {
            int x = adj[i][j];

            if(x == parent)
                continue;
            
            vector<int> child_count = dfs(adj, x, i, labels, ans);

            for(int i = 0; i < 26; i++) {
                cur_node_counts[i] = cur_node_counts[i] + child_count[i];
            }
        }
        
        cur_node_counts[labels[i] - 'a'] = cur_node_counts[labels[i] - 'a'] + 1;

        ans[i] = cur_node_counts[labels[i] - 'a'];
        return cur_node_counts;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        vector<int> ans(n, 0);
        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        dfs(adj, 0, -1, labels, ans);
        return ans;
    }
};