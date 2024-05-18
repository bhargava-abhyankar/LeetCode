class Solution {
public:

    /*
    int is_cycle(vector<vector<int>>& graph, int i, vector<bool> &is_vis, vector<bool> &cur_stack)
    {
        is_vis[i] = true;
        cur_stack[i] = true;

        for(int j = 0; j < graph[i].size(); j++) {
            int x = graph[i][j];

            if(is_vis[x] == false && is_cycle(graph, x, is_vis, cur_stack)) {
                return true;
            } else if (cur_stack[x] == true) {
                return true;
            }
        }

        cur_stack[i] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<bool> is_vis(n, false);
        vector<bool> cur_stack(n, false);
        vector<int> result;

        for(int i = 0; i < n; i++) {
            if(is_vis[i] == false) {
                is_cycle(graph, i, is_vis, cur_stack);
            }
        }

        for(int i = 0; i < n; i++) {
            if(cur_stack[i] == false) {
                result.push_back(i);
            }
        }

        return result;
    }
    */

    bool dfs(vector<vector<int>>& graph, int node, vector<int>& state) 
    {
        /* If the node is already visited, check if it's safe */
        
        if (state[node] == 1) 
            return true;

        /* If the node is currently being visited, it's part of a cycle, not safe */

        if (state[node] == 2) 
            return false;
    
        state[node] = 2; // Mark node as being visited
    
        for (int neighbor : graph[node]) {
            if (!dfs(graph, neighbor, state)) return false; // If any neighbor is not safe, the node is not safe
        }
    
        state[node] = 1; // Mark node as safe
        return true;
    }

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> state(n, 0); // 0: not visited, 1: safe, 2: being visited
    
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        if (dfs(graph, i, state)) result.push_back(i);
    }
    
    return result;
}

};