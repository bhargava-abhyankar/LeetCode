class Solution {
public:

    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        long long int n = time.size();
        long long int start = 1, end = 1e14;

    
        while(start <= end) {
            long long mid = start + (end - start) / 2;
            long long count = 0;

            for(int i = 0; i < n; i++) {
                count = count + mid/ time[i];
            }

            if(count >= totalTrips) {
                end = mid - 1 ;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};