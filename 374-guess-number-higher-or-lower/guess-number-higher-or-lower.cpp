/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:

    /*
    int guessNumber(int n) 
    {
        int start = 1, end = n;

        while(start <= end) {
            long long int mid = ((long long int)((long long int)start + (long long int)end)) / 2;
            int ret = guess(mid);

            if(ret == (long long int) 0) {
                return mid;
            } else if (ret == (long long int) 1) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }

    */


    int guessNumber(int n) 
    {
        int start = 1, end = n;

        while(start <= end) {
            int mid = start + (end - start)/2;

            if(guess(mid) == 0) {
                return mid;
            } else if (guess(mid) == -1) {
                end = mid - 1;
            } else if (guess(mid) == 1) {
                start = mid + 1;
            }
        }

        return -1;
    }
};