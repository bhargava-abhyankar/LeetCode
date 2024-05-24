class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row =  matrix.size();
        int col = matrix[0].size();

        int start = 0, end = (row * col) -1;

        if(start == end && matrix[start][end] == target)
            return true;

        while(start <= end) {
            int mid = (start+end)/2;
            int cur_row = mid/col;
            int cur_col = mid % col;

            cout << mid << " and " << matrix[cur_row][cur_col] << endl;


            if(matrix[cur_row][cur_col] == target) {
                return true;
            } else if (matrix[cur_row][cur_col] > target) {
                end = mid - 1;
            } else if (matrix[cur_row][cur_col] < target ) {
                start = mid +1;
            }
        }

        return false;
    }
};