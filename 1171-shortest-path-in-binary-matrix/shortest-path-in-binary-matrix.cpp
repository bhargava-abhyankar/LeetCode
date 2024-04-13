class Solution {
public:

    bool is_safe(int i, int j, vector<vector<int>>&grid) 
    {
        if(i < 0 || j < 0 || (i > (grid.size()-1)) || (j > (grid[0].size() -1 ))) {
            return false;
        }
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int level = 0;
        vector< vector<int>> direction = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        typedef pair <int, pair<int, int>> P;
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        if(grid[0][0] != 0) {
            return -1;
        }
        
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!pq.empty()) {
            P cur = pq.top();

            int x = cur.second.first;
            int y = cur.second.second;
            pq.pop();

            for(int j = 0; j < direction.size(); j++) {
                int x_ = x + direction[j][0]; 
                int y_ = y + direction[j][1];

                if(is_safe(x_, y_, grid) && (grid[x_][y_] == 0) && (dist[x_][y_] > (cur.first + 1))) {
                    pq.push({cur.first + 1, {x_, y_}});
                    dist[x_][y_] = cur.first + 1;
                }
            }
        }

        if ((dist[grid.size()-1][grid[0].size() - 1]) != INT_MAX)
            return (dist[grid.size()-1][grid[0].size() - 1] + 1);
        else
            return -1;
    }
};