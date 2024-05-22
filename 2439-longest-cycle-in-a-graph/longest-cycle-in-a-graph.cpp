class Solution {
public:

    void is_cycle_dfs(vector<int>& edges, int i, vector<bool> &is_vis, vector<bool> &in_rec, vector<int> &count, int &ans)
    {
        if(i != -1) {
            is_vis[i] = true;
            in_rec[i] = true;

            int x = edges[i];

            if(x != -1 && is_vis[x] == false) {
                count[x] = count[i] + 1;
                is_cycle_dfs(edges, x, is_vis, in_rec, count, ans);
            }
            else if(x != -1 && in_rec[x] == true) {
                ans = max(ans, count[i] - count[x] + 1);
            }

            in_rec[i] = false;
        }
    }
    
    int longestCycle(vector<int>& edges)
    {
        int ans = -1;
        int n =  edges.size();
        vector<bool> is_vis(n, false);
        vector<int> count(n, 1);
        vector<bool> in_rec(n, false);

        for(int i = 0; i < n; i++) {
            if(is_vis[i] == false) {
                is_cycle_dfs(edges, i, is_vis, in_rec, count, ans);
            }
        }

        return ans;
    }
};