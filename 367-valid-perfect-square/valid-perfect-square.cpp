class Solution {
public:

    bool isPerfectSquare(int num) 
    {
        if(num < 2)
            return true;
        
        long long start = 1, end = num/2;

        while(start <= end) {
            long long mid = start + (end - start)/2;
            long long multiple = mid * mid;

            if(multiple == num) {
                return true;
            } else if (multiple < num) {
                start = mid + 1;
            } else if (multiple > num) {
                end = mid - 1;
            }
        }

        return false;
        
    }
};