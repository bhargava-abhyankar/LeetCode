class Solution {
public:

    /* Method 1: Mathematical. O(n) */

    int missingNumber(vector<int>& arr) 
    {
        int n = arr.size();
        int difference = (arr[n-1] - arr[0])/n;

        for(int i = 1; i < n; i++) {
            int expected = arr[0] + (i * difference);

            if(expected != arr[i]) {
                return expected;
            }
        }

        return arr[0];
    }

    /* Method 2 : Binary search O(logn)

    int missingNumber(vector<int>& arr) 
    {
        int n = arr.size();
        int difference = (arr[n-1] - arr[0])/n;

        int start = 0, end = n-1;

        while(start <= end) {
            int mid = start + (end - start)/2;
            int expected = arr[0] + (difference * mid);

            if(arr[mid] != expected) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return (arr[0] + (difference * start));
    }

    */
};