class Solution {
public:

    pair<int, int> get_cordinates(int num, int n)
    {
        int row_top = (num-1)/n;
        int row_bot = (n - 1) - row_top;

        int col = (num-1) % n;

        if( ((n%2 == 1) && (row_bot % 2 == 1)) || ((n%2 == 0) && (row_bot % 2 == 0))) {
            col = (n -1) - col;
        }

        return make_pair(row_bot, col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int level = 0;
        queue<int> q;
        vector<vector<bool>> is_vis(n, vector<bool>(n, false));
        q.push(1);
        is_vis[n-1][0] = true;

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int x = q.front();
                q.pop();

                if(x == n*n) {
                    return level;
                }

                for(int k = 1; k <= 6; k++) {
                    int next = x + k;

                    if(next > n * n)
                        break;
                    
                    pair<int, int> pos = get_cordinates(next, n);
                    int r = pos.first;
                    int j = pos.second;

                    if(is_vis[r][j] == false) {
                        is_vis[r][j] = true;

                        if(board[r][j] == -1) {
                            q.push(next);
                        } else {
                            q.push(board[r][j]);
                        }
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};