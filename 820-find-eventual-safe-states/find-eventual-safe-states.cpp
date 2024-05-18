class Solution {
public:

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
};