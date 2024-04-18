class Solution {
public:

    /*
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<bool> is_vis(n, false);
        vector<int> path;
        queue<int> q;

        q.push(0);
        is_vis[0] = true;

        while(!q.empty())
        {
            int size = q.size();

            if( n-1 == q.front()) {
                vector<int> temp;
                temp = path;
                temp.push_back(q.front()); 
                ans.push_back(temp);
                q.pop();
                path.pop_back();
                continue;
            }

            for(int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();

                for(int j = 0; j < graph[cur].size(); j++) {
                    int x = graph[cur][j];

                    if(is_vis[x] == false) || (x == (n-1)) {
                        q.push(x);
                    }                   
                }
            }
        }
        
        return ans;
    }
    */

    void dfs(vector<vector<int>>& graph, int i, vector<int>&path, vector<vector<int>> &ans, int n)
    {
        path.push_back(i);

        if(i == n-1) {
            ans.push_back(path);
        }

        for(int j = 0; j < graph[i].size(); j++) {
            int x = graph[i][j];
            
           // if(is_vis[x] == false || (x == n-1)) {
                dfs(graph, x, path, ans, n);
                path.pop_back();
           // }
        }
    }

    vector<vector<int>>allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        //vector<bool> is_vis(n, false);

        dfs(graph, 0, path, ans, n);
        return ans;
    }
};