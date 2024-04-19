class Solution {
public:

    /* DFS method */

    /*
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
    */

    /* Union Find Method */

    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) {
            return;
        }

        if(x_parent > y_parent) {
            parent[y_parent] = x_parent;
        }
        else if (x_parent < y_parent) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        parent.resize(n);
        rank.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i = 0; i < edges.size(); i++) {
            Union(edges[i][0], edges[i][1]);
        }

        if(find(source) == find(destination)) {
            return true;
        }

        return false;
    }

};