class Solution {
public:

    /* Idea is to count the number of flowers when blooming day is greater than the refereing day. Since we need only adjecent, 
       if the flower doesnt boom that day, other flowers are also can be taken for boquet, count is reset. 
       once the number of flowers are equal to number of flowers needed in one boquet, reset count and decrement the required boquet
       count. at last if number of boquet is less than zero means in given days m boquets with n flowers can be made
    */

    bool is_possible(vector<int>& bloomDay, long long int cur_day, int m, int k)
    {
        long long int count = 0;

        for(int i = 0; i < bloomDay.size(); i++) {

            if(cur_day >= bloomDay[i]) {
                count = count + 1;
            } else {
                count = 0;
            }

            if(count == k) {
                count = 0;
                m--;
            }
        }

        if( m <= 0) 
            return true;
        else 
            return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int ans = -1;
        int start = 1, end = 1000000000;

        if( (long long int )m*k > (long long int)bloomDay.size())
            return ans;

        while(start <= end) {
            long long int mid = (long long int) (((long long int) start + (long long int) end) / 2);

            if(is_possible(bloomDay, mid, m, k)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return start;
    }
};