class Solution {
public:
    /*  This method is using DFS 

    void dfs(int i, vector<bool> &is_vis, vector<vector<int>>& stones)
    {
        is_vis[i] = true;
    
        for(int j = 0; j < stones.size(); j++) {
            int row = stones[j][0];
            int col = stones[j][1];

            if((stones[i][0] == row) || (stones[i][1] == col)) {
                if(is_vis[j] == false) {
                    dfs(j, is_vis, stones);
                }
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) 
    {
        int count = 0;
        int n = stones.size();
        vector<bool> is_vis(n, false);

        for(int i = 0; i < n; i++) {
            if(is_vis[i] == false) {
                dfs(i, is_vis, stones);
                count++;
            }
        }

        return (n - count);    
    }
    */

    /* This method is using disjoint/ find and union */

    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) {
            return;
        }

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else
        {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size();
        rank.resize(n);
        parent.resize(n);

        for(int i = 0; i < n; i++) {
            rank[i] = 1;
            parent[i] = i;
        }

        for(int i = 0; i < n; i++) {
            for(int j = i +1; j < n; j++) {
                if(stones[j][0] == stones[i][0] || stones[j][1] == stones[i][1])
                    Union(i, j);
            }
        }

        int groups = 0;
        for(int i = 0; i < n; i++) {
            if(find(i) == i) {
                groups++;
            }
        }

        return n - groups;
    }
};