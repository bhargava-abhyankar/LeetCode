class Solution {
public:

    /* DFS approach */

    void dfs(vector<vector<int>>& edges, long long i, vector<bool>& is_vis, long long &count)
    {
        is_vis[i] = true;
        count++;

        for(long long j = 0; j < edges[i].size(); j++) {
            long long x = edges[i][j];

            if(is_vis[x] == false) {
                dfs(edges, x, is_vis, count);
            }
        } 
    }

    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        long long ans = 0;
        long long remaining_nodes = n;
        long long count = 0;
        vector<bool> is_vis(n, false);
        vector<vector<int>>adj(n);

        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(long long i = 0; i < n; i++) {
            if(is_vis[i] == false) {
                count = 0;
                dfs(adj, i, is_vis, count);
                ans = ans + (count * (remaining_nodes - count));
                remaining_nodes = (remaining_nodes - count);
            }
        }

        return ans;
    }

    /*Union Find approach */

    /*
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if(x ==  parent[x])
            return x;
        
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        long long count = 0;
        parent.resize(n);
        rank.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i = 0; i < edges.size(); i++) {
            Union(edges[i][0], edges[i][1]);
        }

        for(int i = 0; i < n; i++) {
            for(int j  = i+1; j < n; j++ ) {
                if(find(i) != find(j)) {
                    count++;
                }
            }
        }

        return count;
    }
    */
};