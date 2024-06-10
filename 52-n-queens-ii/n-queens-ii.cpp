class Solution {
public:

    bool is_possible_to_place(vector<string>&board, int row, int col, int n)
    {
        for(int i = 0; i < n; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        for(int j = 0; j < n; j++) {
            if(board[row][j] == 'Q') {
                return false;
            }
        }

        for(int i = row, j = col; i < n && j < n && i >= 0 && j >= 0; i++, j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        for(int i = row, j = col; i < n && j < n && i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        for(int i = row, j = col; i < n && j < n && i >= 0 && j >= 0; i++, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        for(int i = row, j = col; i < n && j < n && i >= 0 && j >= 0; i--, j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solve(vector<string>&board, int row, int &ans, int n, int count)
    {
        if(row == n && count == n) {
            ans = ans + 1;
            return;
        } else if (row == n) {
            return;
        }

        for(int i = 0; i < n; i++) {
            if(is_possible_to_place(board, row, i, n)) {
                board[row][i] = 'Q';
                count++;
                solve(board, row + 1, ans, n, count);
                count--;
                board[row][i] = '.';
            }
        }
    }

    int totalNQueens(int n) 
    {
        int ans = 0;
        vector<string>board(n, string(n, '.'));
        solve(board, 0, ans, n, 0);
        return ans;
    }
};