class Solution {
public:

    /* Approach: Fixed window size problem. when window size reaches k, calculate avg using cur_sum and k. if avg greater the threashold,
       count it as ans. then reduce the val at left from sum and  increment the left. 

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

    */

    int numOfSubarrays(vector<int>&nums, int k, int threshold) {
        int i=0,j=0,n=nums.size(),sum=0,ans=0;
        while(j<n){
            sum+=nums[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                int avg=sum/k;
                if(avg>= threshold){
                    ans++;
                }
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }
    
};