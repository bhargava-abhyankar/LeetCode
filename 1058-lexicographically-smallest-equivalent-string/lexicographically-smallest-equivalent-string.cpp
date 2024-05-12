class Solution {
public:

    /*this approach is not optimized */

    /*
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
    */

    /* Using Union find method */

    vector<int> parent;

    char find (char x)
    {
        if( x == parent[x])
            return x;
        
        return parent[x] = find(parent[x]);
    }

    void Union(char x, char y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent < y_parent) {
            parent[y_parent] = x_parent;
        }
        else if (x_parent > y_parent) {
            parent[x_parent] = y_parent;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        string result;
        parent.resize(26, 0);

        for(int i = 0; i < 26; i ++) {
            parent[i] = i;
        }

        for(int i = 0; i < s1.length(); i++) {
            Union((s1[i] - 'a'), (s2[i] - 'a'));
        }

        for(int i = 0; i < baseStr.length(); i++) {
            result.push_back(find(baseStr[i] - 'a') + 'a');          
        }

        return result;
    }

};