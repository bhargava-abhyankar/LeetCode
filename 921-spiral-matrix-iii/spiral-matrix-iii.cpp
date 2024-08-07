class Solution {
public:

    /*
        Initially, we are located at the coordinates rStart and cStart and must make our first movement 
        toward the East. Let's simulate the clockwise movement and note the distances moved with each 
        direction to identify any patterns:

        Move 1 unit towards the East.
        Move 1 unit towards the South.
        Move 2 units towards the West.
        Move 2 units towards the North.
        Move 3 units towards the East.
        Move 3 units towards the South.
        Move 4 units towards the West.
        Move 4 units towards the North.
        and so on...
        We observe a pattern where distances are covered in pairs of directions, 
        increasing the distance by 1 after each pair. 
        Specifically, we move in the order of East, South, West, and North, 
        increasing the distance after every pair.

        To implement this, we can store the directional movements in an array: for instance, East corresponds 
        to (x+0, y+1) and South to (x+1, y+0). We then simulate the process by taking two directions 
        simultaneously and increasing the step size after every pair. If the current cell lies within the matrix, 
        we append it to the traversed matrix. We return traversed once all matrix cells have been covered.

     */

    bool is_valid(int &rstart, int &cStart, int &rows, int &cols)
    {
        if(rstart < rows && cStart < cols && rstart >= 0 && cStart >= 0) {
            return true;
        } else {
            return false;
        }
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) 
    {
        vector<vector<int>> ans;
        vector<vector<int>> all_directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0, step = 1;

        while(ans.size() < rows * cols) {

            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < step; j++) {
                    if(is_valid(rStart, cStart, rows, cols)) {
                        ans.push_back({rStart, cStart});
                    }
                    rStart = rStart + all_directions[direction][0];
                    cStart = cStart + all_directions[direction][1];
                }

                direction = (direction + 1) % 4;
            }
            step = step + 1;
        }

        return ans;
    }
};