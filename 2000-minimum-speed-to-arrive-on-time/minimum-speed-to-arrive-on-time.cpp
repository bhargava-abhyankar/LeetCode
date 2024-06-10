class Solution {
public:

    bool is_reachable(vector<int>& dist, int n, double cur, double hour)
    {
        double count = 0;

        for(int i = 0; i < n -1; i++) {
            count = count + ceil((double)dist[i]/(double)cur);
        }

        count = count + ((double)dist[n-1]/(double)cur);

        if(count <= hour) {
            return true;
        }

        count = ceil(count);

        if(count <= hour) {
            return true;
        }

        return false;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int ans = -1;
        int n = dist.size();
        int start = 1, end = 1e7;

        if(hour < (n -1))
            return -1;

        
        cout << start << " " << end << endl;

        while(start <= end) {
            long long int mid = (start + end)/2;

            if(is_reachable(dist, n, mid, hour)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }

};