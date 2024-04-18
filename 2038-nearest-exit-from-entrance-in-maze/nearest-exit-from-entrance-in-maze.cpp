class Solution {
public:

    bool is_safe(int i, int j, int row, int col)
    {
        if(i < 0 || j < 0 || (i > row-1) || (j > col-1)) {
            return false;
        }
        return true;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        bool is_reached = false;
        int level = 0;
        int row = maze.size();
        int col = maze[0].size();
        vector<vector<int>>is_vis(row, vector<int>(col,false));

        vector<vector<int>> direction = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        is_vis[entrance[0]][entrance[1]] = true;

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                pair<int, int> cur = q.front();
                q.pop();

                for(int j = 0; j < direction.size(); j++) {
                    int x = cur.first + direction[j][0];
                    int y = cur.second + direction[j][1];
                    
                    if(is_safe(x, y, row, col)) {
                        if(is_vis[x][y] == false && maze[x][y] == '.') {
                            is_vis[x][y] = true;
                            q.push({x, y});
                        }
                    }
                    else {
                        if(level != 0) {
                            return level;
                        }
                    }
                }
            }
            level++;
        }

        return -1;
    }
};