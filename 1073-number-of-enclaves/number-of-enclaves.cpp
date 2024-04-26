class Solution {
public:

    bool is_safe(vector<vector<int>>& grid, int i, int j, bool &is_on_edge)
    {
        if( i < 0 || j < 0 || (i > (grid.size() -1)) || (j > (grid[0].size() -1))) {
            is_on_edge = true;
            return false;
        }

        return true;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, bool &is_on_edge, int &count)
    {
        grid[i][j] = 0;
        count++;
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(int k = 0; k < direction.size(); k++) {
            int i_ = i + direction[k][0];
            int j_ = j + direction[k][1];

            if(is_safe(grid, i_, j_, is_on_edge) && (grid[i_][j_] == 1)) {
                dfs(grid, i_, j_, is_on_edge, count);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) 
    {
        int num_of_enaclaves = 0;
        bool is_on_edge = false;
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {

                    is_on_edge = false;
                    count = 0;

                    dfs(grid, i, j, is_on_edge, count);

                    if(!is_on_edge) { 
                        num_of_enaclaves = num_of_enaclaves + count; 
                    }
                }
            }
        }

        return num_of_enaclaves;        
    }
};