class Solution {
public:
    
    /* Method 1: Two pointer */
    
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int start = 0, end = n-1, ans = 0;

        while(start < end) {
            int width = end - start;
            ans = max(ans, min(height[start], height[end]) *width) ;

            if(height[start] <= height[end]) {
                start++;
            } else {
                end--;
            }
        }

        return ans;
    }
};