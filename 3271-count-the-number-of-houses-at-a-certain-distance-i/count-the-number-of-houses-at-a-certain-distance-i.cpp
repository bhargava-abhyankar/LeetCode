class Solution {
public:

    void bfs(int source, vector<vector<int>> &adj, int &n, vector<int> &dist)
    {
        queue<pair<int, int>> q;
        q.push({source, 0});
        dist[source] = 0;

        while(!q.empty()) {
            int cur_size = q.size();

            for(int i = 0; i < cur_size; i++) {
                auto cur = q.front();
                int u = cur.first;
                q.pop();

                for(int j = 0; j < adj[u].size(); j++) {
                    int x = adj[u][j];

                    if(dist[u] + 1 < dist[x]) {
                        dist[x] = dist[u] + 1;
                        q.push({x, dist[u] + 1});
                    }
                }
            }
        }
    }

    vector<int> countOfPairs(int n, int x, int y) 
    {
        vector<int>ans(n, 0);
        vector<vector<int>>adj(n+1);

        for(int i = 1; i < n; i++) {
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }

        if(x != y) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for(int i = 1; i <=n; i++) {
            vector<int> dist(n+1, INT_MAX);
            bfs(i, adj, n, dist);

            for(int j = 0; j < n+1; j++) {
                if(dist[j] == 0 || dist[j] == INT_MAX)
                    continue;
                ans[dist[j]-1]++;
            }
        }

        return ans;      
    }
};