class Solution {
public:

    int disktraw(int src, int n, vector<vector<pair<int, int>>> &adj, int distanceThreshold)
    {
        int count = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            int cur = pq.top().second;
            int cur_weight = pq.top().first;
            pq.pop();

            for(int j = 0; j < adj[cur].size(); j++) {
                int neigh = adj[cur][j].first;
                int n_weight = adj[cur][j].second;

                if(cur_weight + n_weight < dist[neigh]) {
                    dist[neigh] = cur_weight + n_weight;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            count += dist[i] <= distanceThreshold ;             
        }

        return count;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        int ans = -1,  max = 1e9;
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < edges.size(); i++) {
            int node = edges[i][0];
            int neigh = edges[i][1];
            int weight = edges[i][2];
            adj[node].push_back({neigh, weight});
            adj[neigh].push_back({node, weight});

        }

        for(int i = 0; i < n; i++) {
            int res = disktraw(i, n, adj, distanceThreshold);
            cout << res << endl;
            if(res <= max) {
                max = res;
                ans = i;
            }
        }

        return ans;
    }
};