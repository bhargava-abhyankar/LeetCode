class Solution {
public:

    void dfs(int n, vector<int>& edges, int i, vector<int>& dist, vector<bool>& is_vis)
    {
        is_vis[i] = true;
        int x = edges[i];

        if(x != -1 && is_vis[x] == false) {
            if(dist[x] > (dist[i] + 1)) {
                dist[x] = dist[i] + 1;
            }
            dfs(n, edges, x, dist, is_vis);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n = edges.size();
        vector<int>dist1(n, INT_MAX);
        vector<int>dist2(n, INT_MAX);
        vector<bool> is_vis1(n, false);
        vector<bool> is_vis2(n, false);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(n, edges, node1, dist1, is_vis1);
        dfs(n, edges, node2, dist2, is_vis2);

        int min_till_now = INT_MAX;
        int min_index = -1;
    
        for(int i = 0; i < n; i++) {
            int maxd = max(dist1[i], dist2[i]);

            if(min_till_now > maxd) {
                min_till_now = maxd;
                min_index = i;
            }
        }
        
        return min_index;
    }
};