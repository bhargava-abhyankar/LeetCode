class Solution {
public:

    /*
        Algo:
        1. take 4 variables. row_start, col_start, row_end and col_end.  row_end and col_end are n-1. 
        2. do looping of below logic till they start cross end.
        3. one each for loop to traverse left to right and up to down.
        4. then check if row_start <= row_end, then traverse right to left. 
        5. check if col_start <= col_end then down to up.

     */

    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if(matrix.size() == 0)
		    return vector<int>();

	    vector<int> ans;
	    int row_start = 0, col_start = 0, row_max = matrix.size()-1, col_max = matrix[0].size()-1, i, j;

	    while(row_start <= row_max && col_start <= col_max) {
	
		    for(int j = col_start; j <= col_max; j++) {
			    ans.push_back(matrix[row_start][j]);
		    }
		
		    row_start++;
		
		    for(int i = row_start; i <= row_max; i++) {
			    ans.push_back(matrix[i][col_max]);
		    }
		
		    col_max--;
		
		    if(row_start <= row_max) {
			    for(int j = col_max; j >= col_start; j--) {
				    ans.push_back(matrix[row_max][j]);
			    }
		    }
		
		    row_max--;
		
		    if(col_start <= col_max) {
			    for(int i = row_max; i >= row_start; i--) {
				    ans.push_back(matrix[i][col_start]);
			    }
		    }
		
		    col_start++;
	    }

	    return ans;
    }
};