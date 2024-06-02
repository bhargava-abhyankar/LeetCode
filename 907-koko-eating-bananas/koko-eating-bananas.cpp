class Solution {
public:

    bool is_possible(vector<int>& piles, int cur_rate, int h)
    {
        long long required_hours_at_cur_rate = 0;
         
        for(int i = 0; i < piles.size(); i++) {
            required_hours_at_cur_rate = required_hours_at_cur_rate + ceil(1.0 * piles[i] / cur_rate);
        }

        if(required_hours_at_cur_rate <= h) {
            return true;
        }

        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int start = 1, end = INT_MIN;

        for(int i = 0; i < piles.size(); i++) {
            end = max(end, piles[i]);
        }

        while(start <= end) {
            long long int mid = (long long int )((long long int) start + (long long int ) end) / 2;

            if(is_possible(piles, mid, h)) {
                end = mid-1;
            }
            else {
                start = mid + 1;
            }
        }

        return start;
    }


};