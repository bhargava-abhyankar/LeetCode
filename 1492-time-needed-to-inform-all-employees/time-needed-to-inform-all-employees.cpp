class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        vector<vector<int>> adj(n);
        vector<int> is_visited(n, false);

        int ans = 0;
        if(n == 1)
            return ans;
        
        for(int i = 0; i < manager.size(); i++) {
            if(manager[i] != -1) {
                adj[manager[i]].push_back(i);
                adj[i].push_back(manager[i]);
            }
        }

        queue<pair<int, int>> q;
        q.push({headID, informTime[headID]});
        is_visited[headID] = true;

        while(!q.empty()) {
            int i = q.front().first;
            int cur_time = q.front().second;
            q.pop();

            for(int j = 0; j < adj[i].size(); j++) {
                int x = adj[i][j];

                ans = max(ans, cur_time);

                if(is_visited[x] == false) {
                    is_visited[x] = true;
                    q.push({x, cur_time + informTime[x]});
                }
            }
        }

        return ans;
    }
};