class Solution {
public:

    int arrangeCoins(int n) 
    {
        long long start = 0, end = n;

        while(start <= end) {
            long long mid = start + (end - start)/2;
            long long coins = (mid * (mid + 1))/2;

            if(coins == n) {
                return mid;
            } else if (coins < n) {
                start = mid + 1;
            } else if (coins > n) {
                end = mid -1;
            }
        }

        return end;
    }
};