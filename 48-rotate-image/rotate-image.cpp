class Solution {
public:

    void transpose(vector<vector<int>>& matrix)
    {
	    int n = matrix.size();
	
	    for(int i = 0; i < n; i++) {
		    for(int j = i+1; j < n; j++) {
			    int temp = matrix[i][j];
			    matrix[i][j] = matrix[j][i];
			    matrix[j][i] = temp;
	    	}
	    }
    }

    void reverse_transpose(vector<vector<int>>& matrix)
    {
	    int n = matrix.size();
	
	    for(int i = 0; i < n; i++) {
		    for(int j = 0; j < n/2; j++) {
			    int temp = matrix[i][j];
			    matrix[i][j] = matrix[i][n - j - 1];
			    matrix[i][n - j - 1] = temp;
		    }
	    }
    }

    void rotate(vector<vector<int>>& matrix) 
    {
        transpose(matrix);
	    reverse_transpose(matrix);    
    }
};