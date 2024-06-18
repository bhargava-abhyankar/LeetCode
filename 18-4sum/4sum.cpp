class Solution {
public:

    void two_sum(vector<int>& nums, int num1, int num2, int i, int target, vector<vector<int>> &ans)
    {
        int j = nums.size()-1;

        while(i < j) {
            long long sum = (long long) (nums[i] + nums[j]); 
            sum = (long long) (sum + num1); 
            sum = (long long) (sum + num2);

            if(sum == target) {
                ans.push_back({num1, num2, nums[i], nums[j]});

                while(i < j && nums[i] == nums[i+1]) {
                    i++;
                }
                while(i < j && nums[j] == nums[j-1]) {
                    j--;
                }
                i++;
                j--;

            } else if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ans;

        if(nums.size() < 4)
            return ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-3; i++) {
            if(i !=0 && nums[i] == nums[i-1]) {
                continue;
            }

            for(int j = i+1; j < nums.size()-2; j++) {
                if( j > (i+1) && nums[j] == nums[j-1]) {
                    continue;
                }

                two_sum(nums, nums[i], nums[j], j+1, target, ans);
            }
        }

        return ans;
    }


    /*
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(i > 0 and nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n; j++)
            {
                if(j > (i + 1) and nums[j] == nums[j - 1]) continue;
                
                int start = j + 1;
                int end = n - 1;

                while(start < end)
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[start];
                    sum += nums[end];

                    if(sum == target)
                    {
                        ans.push_back({nums[i] , nums[j] , nums[start] , nums[end]});
                        int low = nums[start];
                        int high = nums[end];
                        start++,end--;
                        while(start < end and nums[start] == low) start++;
                        while(start < end and nums[end] == high) end--;
                    }
                    else if(sum > target) end--;
                    else start++;
                }
            }
        }
        return ans;
    }
    */
};