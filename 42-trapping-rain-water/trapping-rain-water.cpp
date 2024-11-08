class Solution {
public:

    /* Method 1: Brute force, gives time limit exceeded 

    int trap(vector<int>& height) 
    {
        int ans = 0;
        int n = height.size();

        for(int i = 1; i < n; i++) {
            int left_max = 0, right_max = 0;

            for(int j = i; j >= 0; j--) {
                left_max = max(left_max, height[j]);
            }

            for(int j = i; j < n; j++) {
                right_max = max(right_max, height[j]);
            }

            ans = ans + min(left_max, right_max) - height[i];
        }

        return ans;
    }

    */

    int trap(vector<int>& height) 
    {
        int ans = 0;
        int size = height.size();
        int left[size], right[size];
        left[0] = height[0];
        right[size-1] = height[size-1];

        for(int i = 1; i < size; i++) {
            left[i] = max(height[i], left[i-1]);
        }

        for(int j = size-2; j >= 0; j--) {
            right[j] = max(height[j], right[j + 1]);
        }

        for(int i = 0; i < size; i++) {
            ans = ans + min(left[i], right[i]) - height[i];
        }

        return ans;
    }



};