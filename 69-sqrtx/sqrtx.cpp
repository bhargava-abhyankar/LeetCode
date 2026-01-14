class Solution {
public:
    /*
    int mySqrt(int x) 
    {
        if(x == 0 || x == 1)
            return x;
        
        int start = 1, end = x / 2;
        int mid = 0;

        while(start <= end) {
            mid = (start + end) / 2;
            long long int square = (long long int)mid * mid;

            if (square == x) {
                return mid;
            }
            else if(square > x) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return start - 1;
    }

    */

    int mySqrt(int x) 
    {
        if(x < 2)
            return x;

        int start = 1, end = x/2;

        while(start <= end) {
            int mid = start + (end - start)/2;
            long long int root = (long long int) mid * mid;

            if(root == x) {
                return mid;
            } else if (root < x) {
                start = mid + 1;
            } else if (root > x) {
                end = mid - 1;
            }
        }

        return end;
    }
};