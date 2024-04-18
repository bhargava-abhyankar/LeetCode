class Solution {
public:

    void dfs(vector<vector<int>>& rooms, int i, vector<bool> &is_vis, int &count)
    {
        is_vis[i] = true;
        count++;

        for(int j = 0; j < rooms[i].size(); j++) {
            int x = rooms[i][j];

            if(is_vis[x] == false) {
                dfs(rooms, x, is_vis, count);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<bool> is_vis(n, false);
        int count = 0;

        dfs(rooms, 0, is_vis, count);

        if(count == n) {
            return true;
        }

        return false;        
    }
};