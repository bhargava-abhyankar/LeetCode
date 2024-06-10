class Solution {
public:

    bool is_placeable(vector<string> &board, int row, int col, int n)
    {
        int i = row, j = col;

        for(int k = 0; k < n; k++) {
            if(board[row][k] == 'Q') {
                return false;
            }
        }

        for(int k = 0; k < n; k++) {
            if(board[k][col] == 'Q') {
                return false;
            }
        }
    
        i = row, j = col;

        while(i >= 0 && j >= 0 && i <= n-1 && j <= n-1) {
            if(board[i][j] == 'Q') {
                return false;
            }
            j++;
            i++;
        }

        i = row, j = col;

        while(i >= 0 && j >= 0 && i <= n-1 && j <= n-1) {
            if(board[i][j] == 'Q') {
                return false;
            }
            j--;
            i--;
        }

        i = row, j = col;

        while(i >= 0 && j >= 0 && i <= n-1 && j <= n-1) {
            if(board[i][j] == 'Q') {
                return false;
            }
            j++;
            i--;
        }

        i = row, j = col;

        while(i >= 0 && j >= 0 && i <= n-1 && j <= n-1) {
            if(board[i][j] == 'Q') {
                return false;
            }
            j--;
            i++;
        }
        
        return true;
    }

    void solve(vector<string> &board, int row, vector<vector<string>> &ans, int n, int count)
    {
        if(row == n && count == n) {
            ans.push_back(board);
            return;
        }

        for(int k = 0; k < n; k++) {
            if(is_placeable(board, row, k, n)) {
                board[row][k] = 'Q';
                count++;
                solve(board, row+1, ans, n, count);
                board[row][k] = '.';
                count--;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(board, 0, ans, n, 0);
        return ans;
    }
};