class Solution {
public:

    bool is_valid(vector<vector<char>>& board, int i, int j)
    {
        if(i >= 0 && i <= (board.size()-1) && j >= 0 && j <= (board[0].size()-1)) {
            return true;
        }
        return false;
    }

    void dfs(vector<vector<char>>& board, string &match, int row, int col, string word, bool &ans, int i)
    {
        if(match == word) {
            ans = true;
            return;
        }

        if(is_valid(board, row, col) && board[row][col] != ' ') {
            char x = board[row][col];
            match.push_back(x);
            board[row][col] = ' ';

            if(x == word[i]) {
                dfs(board, match, row+1, col, word, ans, i+1);
                dfs(board, match, row-1, col, word, ans, i+1);
                dfs(board, match, row, col+1, word, ans, i+1);
                dfs(board, match, row, col-1, word, ans, i+1);
            }
            match.pop_back();
            board[row][col] = x;
        }
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        string match;
        bool ans = false;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board, match, i, j,  word, ans, 0);
                if(ans == true) {
                    return ans;
                }              
            }
        }
        return ans;
    }
};