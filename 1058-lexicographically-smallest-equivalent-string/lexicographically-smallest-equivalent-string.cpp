class Solution {
public:

    void dfs(unordered_map<char, vector<char>> &adj, char i, vector<int> &is_vis, char &ret)
    {
        is_vis[i] = 1;
        ret = min(ret, i);

        for(int j = 0; j < adj[i].size(); j++) {
            char x = adj[i][j];

            if(is_vis[x] == 0) {
                dfs(adj, x, is_vis, ret);    
            }
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        char ret;
        int n = s1.length();
        int m =  baseStr.length();
        string result;

        unordered_map<char, vector<char>> adj;
        vector<int> is_vis(256, 0);

        for(int i = 0; i < n; i++) {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }

        for(int i = 0; i < m; i++) {
            vector<int> temp(256, 0);
            is_vis = temp;
            ret =  baseStr[i];
            dfs(adj, baseStr[i], is_vis, ret);
            result.push_back(ret); 
        }

        return result;
    }
};