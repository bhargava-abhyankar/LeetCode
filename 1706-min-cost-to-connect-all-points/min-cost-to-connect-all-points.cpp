class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int min_cost = 0;
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;   // weight, node
        vector<int> is_vis(n, false);
        vector<int> dist(n, INT_MAX);

        for(int i = 0; i < n ; i++) {
            for(int j = i + 1; j < n; j++) {
                int xi = points[i][0];
                int yi = points[i][1];
                int xj = points[j][0];
                int yj = points[j][1];
                int dist = abs((abs(xi - xj) + abs(yi - yj)));
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        pq.push({0, 0});

        while(!pq.empty()) {
            int cur = pq.top().second;
            int cur_weight = pq.top().first;
            pq.pop();

            if(is_vis[cur] == true )
                continue;
            
            is_vis[cur] = true;
            min_cost = min_cost + cur_weight; 

            for(int i = 0; i < adj[cur].size(); i++) {
                int x = adj[cur][i].first;
                int x_weight = adj[cur][i].second;

                if(!is_vis[x] ) {
                    pq.push({x_weight, x});
                }
            }
        }

        return min_cost;
    }
};