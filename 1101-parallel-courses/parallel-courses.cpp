class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) 
    {
        queue<int> q;
        vector<vector<int>> adj(n+1);
        vector<int>indegree(n+1, 0);
        vector<int> ans;
        int level = 0;

        for(int i = 0; i < relations.size(); i++) {
            adj[relations[i][0]].push_back(relations[i][1]);
            indegree[relations[i][1]]++;
        }

        for(int i = 1; i <=n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                int cur = q.front();
                ans.push_back(cur);
                q.pop();

                for(int j = 0; j < adj[cur].size(); j++) {
                    int x = adj[cur][j];
                    indegree[x]--;

                    if(indegree[x] == 0) {
                        q.push(x);
                    }
                }
            }
            level++;
        }

        if(ans.size() < n)
            return -1;
            
        return level;
    }
};