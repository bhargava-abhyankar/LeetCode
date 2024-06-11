class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        if(c < 3)
        {
            return true;
        }

        bool ans = false;
        int start = 0, end = sqrt(c);

        while(start <= end) {
            long long product = (long long) ((long long)(start * start) + (long long)(end * end) );

            if(product == c) {
                ans = true;
                return ans;
            } else if (product > c) {
                end = end - 1;
            } else {
                start = start + 1;
            }
        }

        return ans;        
    }
};