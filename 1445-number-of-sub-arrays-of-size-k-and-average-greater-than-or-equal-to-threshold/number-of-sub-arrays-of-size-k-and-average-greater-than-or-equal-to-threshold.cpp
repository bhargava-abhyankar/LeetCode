class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int left = 0, right = 0, cur_sum = 0, ans = 0;

        while(right < arr.size()) {
            cur_sum = cur_sum + arr[right];

            if ((right - left + 1) == k) {
                int avg = cur_sum / k;
                if(avg >= threshold) {
                    ans++;
                }
                cur_sum = cur_sum - arr[left];
                left++;
            }

            right++;
        }

        return ans;
    }
};