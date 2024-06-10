class Solution {
public:

    long long find_cost(vector<int>& nums, vector<int>& cost, long long int cur)
    {
        long long count = 0;

        for(int i = 0; i < nums.size(); i++) {
            count = count + ((long long)(abs(nums[i] - cur) * cost[i]));
        }

        return count;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        long long ans = INT_MAX;

        int start = 1, end = 1000000;

        while(start <= end) {
            long long mid = (start + end) / 2;

            long long int mid_cost = find_cost(nums, cost, mid);
            long long int mid_plus_cost = find_cost(nums, cost, mid + 1);

            ans = min(mid_cost, mid_plus_cost);

            if(mid_cost <= mid_plus_cost) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};