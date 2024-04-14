class Solution {
public:

    bool is_safe(int i, int j, vector<vector<int>>& grid)
    {
        if( (i < 0) || (j < 0) || (i > (grid.size() -1)) || (j > (grid[0].size() -1))) {
            return false;
        }

        return true;
    }

    void bfs(int i, int j, vector<vector<int>>& grid, int &ans)
    {
        int count = 0;
        vector<vector<int>>direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1;

        while(!q.empty()) {
            int size = q.size();
            count = count + size;

            for(int x = 0; x < size; x++) {
                auto cur = q.front();
                q.pop();

                for(int y = 0; y < direction.size(); y++) {
                    int i_ = cur.first + direction[y][0];
                    int j_ = cur.second + direction[y][1];

                    if(is_safe(i_, j_, grid) && grid[i_][j_] == 1) {
                        grid[i_][j_] = -1;
                        q.push({i_, j_});
                    }
                }
            }
        }

        ans = max(ans, count);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int ans = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    bfs(i, j, grid, ans);
                }
            }
        }

        return ans;
    }
};