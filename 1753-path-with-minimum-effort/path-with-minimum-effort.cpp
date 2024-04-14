class Solution {
public:

    bool is_safe(int i, int j, vector<vector<int>>& heights)
    {
        if(i < 0 || j < 0 || (i > (heights.size()-1)) || (j > (heights[0].size() -1))) {
            return false;
        }
        return true;
    }

    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        typedef pair<int, pair<int, int>> P;
        int n = heights.size();                                  
        vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0} };
        vector<vector<int>> dist(n, vector<int>(heights[0].size(), INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!pq.empty()) {
            P cur = pq.top();
            int x = cur.second.first;
            int y = cur.second.second;
            int cur_weight = cur.first;
            pq.pop();

            for(int i = 0; i < direction.size(); i++) {
                int x_ = x + direction[i].first;
                int y_ = y + direction[i].second;

                if(is_safe(x_, y_, heights)) {
                    int absdiff = abs(heights[x_][y_] - heights[x][y]);
                    int maxdiff = max(cur_weight, absdiff);

                    if( dist[x_][y_] > maxdiff ) {
                        dist[x_][y_] = maxdiff;
                        pq.push({maxdiff, {x_, y_}});
                    }
                }
            }
        }

        return (dist[heights.size()-1][heights[0].size()-1]);
    }
};