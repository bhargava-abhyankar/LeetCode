class Solution {
public:

    /* method 1: DFS and Binary search */

    void check(vector<vector<int>>&matrix, int i, int j, bool &ans)
    {
        if(i < 1 || i >= matrix.size() || j < 1 || j >= matrix[0].size())
            return;

        if(matrix[i][j] == 1) {
            return;
        }

        if(i == (matrix.size()-1) &&  matrix[i][j] == 0) {
            ans = true;
            return;
        }

        matrix[i][j] = 1;

        check(matrix, i+1, j, ans);
        check(matrix, i, j+1, ans);
        check(matrix, i-1, j, ans);
        check(matrix, i, j-1, ans);
    }

    void copyMatrix(const std::vector<std::vector<int>>& from, std::vector<std::vector<int>>& to) 
    {
        to.clear();
        to.resize(from.size());

        for (size_t i = 0; i < from.size(); ++i) {
            to[i].resize(from[i].size());

            for (size_t j = 0; j < from[i].size(); ++j) {
                to[i][j] = from[i][j];
            }
        }
    }
    
    bool is_possible_to_cross(vector<vector<int>> &matrix)
    {
        bool ans = false;

        for(int i = 1; i < matrix[0].size(); i++) {
 
            if(matrix[1][i] == 0) {
                check(matrix, 1, i, ans);
                if(ans == true) {
                    return true;
                }
            }
        }
        return ans;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        int start = 1, end = cells.size()-1, ans = 0;

        while(start <= end) {
            long long mid = (start + end) / 2;

            vector<vector<int>> matrix(row+1, vector<int>(col+1, 0));

            for(int k = 0; k < mid; k++) {
                int i = cells[k][0];
                int j = cells[k][1];

                matrix[i][j] = 1;
            }

            if(is_possible_to_cross(matrix)) {
                start = mid + 1;
                ans = mid;
            } else {
                end = mid - 1;
            }
        }
        
        return ans;
    }

    /*Method 2: Binary search and BFS */

};