class Solution {
public:

    /* DFS method */

    bool is_similar(string str1, string str2)
    {
        int n = str1.length();
        int diff = 0;

        /* here we need to determine only how many places the strings are different, no need to swap and check if they are equal. if the 
        *  diff is greater than 2 then false */
        
        for(int i = 0; i < n; i++) {
            if(str1[i] != str2[i])
                diff++;
        }

        return( diff == 0 || diff == 2);

    }

    void dfs(vector<vector<int>> &adj, int i, vector<bool> &is_vis)
    {
        is_vis[i] = true;

        for(int j = 0; j < adj[i].size(); j++) {
            int x = adj[i][j];

            if(is_vis[x] == false) {
                dfs(adj, x, is_vis);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size(), count = 0;
        vector<vector<int>> adj(n);
        vector<bool> is_vis(n, false);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                if(is_similar(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(is_vis[i] == false) {
                dfs(adj, i, is_vis);
                count++;
            }
        }
        return count;
    }
};