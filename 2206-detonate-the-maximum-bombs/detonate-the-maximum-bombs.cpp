class Solution {
public:

    void dfs(vector<vector<int>> &adj, int i, vector<bool> &is_vis, int &count)
    {
        is_vis[i] = true;
        count++;

        for(int j = 0; j < adj[i].size(); j++) {
            int x = adj[i][j];
            
            if(is_vis[x] == false) {
                dfs(adj, x , is_vis, count);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int result = 0;
        int count = 0;
        int n = bombs.size();
        vector<vector<int>> adj(n);
        vector<bool> is_vis(n, false);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++ ) {
                if(i == j) {
                    continue;
                }

                int x1 = bombs[i][0];
                int y1 = bombs[i][1];
                long long r1 = bombs[i][2];
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                long long r2 = bombs[j][2];

                long long dist = (pow((x2-x1), 2) + pow((y2-y1), 2));

                if( dist <= ((long long) r1 * r1)) {
                    adj[i].push_back(j);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            count = 0;
            is_vis = vector(n, false);
            dfs(adj, i , is_vis, count);
            result = max(result, count);
        }
        
        return result;
    }

};