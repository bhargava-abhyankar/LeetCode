class Solution {
public:

    /* take 4 variables. row_start, col_start, row_end and col_end. row_end and col_end are n-1. 
       do looping of below logic till they start cross end.
       one each for loop to traverse left to right and up to down. then check if row_start <= row_end, then
       traverse right to left. check if col_start <= col_end then down to up.
     */

    vector<vector<int>> generateMatrix(int n) 
    {
        int max_number = n * n, row_start = 0, col_start = 0, row_end = n-1, col_end = n-1, cur_number = 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));

        while(row_start <= row_end && col_start <= col_end) {

            /* Traverse from left to right across the top row */

            for(int j = col_start; j <= col_end; j++) {
                ans[row_start][j] = cur_number;
                cur_number++;
            }
            row_start++;      

            /* Traverse from top to bottom along the rightmost column */

            for(int i = row_start; i <= row_end; i++) {
                ans[i][col_end] = cur_number;
                cur_number++;
            }
            col_end--;

            /* Traverse from right to left across the bottom row, if there are remaining rows */

            if(row_start <= row_end) {
                for(int j = col_end; j >= col_start; j--) {
                    ans[row_end][j] = cur_number;
                    cur_number++;
                }
            }
            row_end--;

            /* Traverse from bottom to top along the leftmost column, if there are remaining columns */

            if(col_start <= col_end) {
                for(int i = row_end; i >= row_start; i--) {
                    ans[i][col_start] = cur_number;
                    cur_number++; 
                }
            }
            col_start++;
        }

        return ans;
    }
};