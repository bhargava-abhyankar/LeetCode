class Solution {
public:

    /* Method 1: 2 traversal and using extra space to note row and col with zero. 
       first traverse mark row and col where zero is present. then second traverse
       if either row or col found, mark it as zero 

    void setZeroes(vector<vector<int>>& matrix) 
    {
        unordered_set<int> row, col;

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(row.find(i) != row.end() || col.find(j) != col.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    */

    /* Method 2: */

    void setZeroes(vector<vector<int>>& matrix) 
    {
        bool is_row_zero = false, is_col_zero = false;

        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                is_col_zero = true;
                break;
            }
        }

        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[0][j] == 0) {
                is_row_zero = true;
                break;
            }
        }

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[i].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if(is_row_zero) {
            for(int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }

        if(is_col_zero) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};