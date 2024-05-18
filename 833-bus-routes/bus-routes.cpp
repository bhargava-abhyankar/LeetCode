class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        int result = 1;
        int n = routes.size();
        vector<bool> is_vis((n+1), false);
        unordered_map<int, vector<int>> adj;

        if(source == target) {
            return 0;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < routes[i].size(); j++) {
                int x = routes[i][j];
                adj[x].push_back(i);
            }
        }

        queue<int> q;
        auto initial = adj[source];

        for(int i = 0; i < initial.size(); i++) {
            q.push(initial[i]);
            is_vis[initial[i]] = true;
        }

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                int cur_index = q.front();
                q.pop();

                for(int j = 0; j < routes[cur_index].size(); j++) {

                    if(routes[cur_index][j] == target) {
                        return result;
                    }

                    auto next_route = adj[routes[cur_index][j]];

                    for(int k = 0; k < next_route.size(); k++) {
                        if(is_vis[next_route[k]] == false) {
                            q.push(next_route[k]);
                            is_vis[next_route[k]] = true;
                        }
                    }             
                }
            }
            result++;
        }

        return -1;
    }
};