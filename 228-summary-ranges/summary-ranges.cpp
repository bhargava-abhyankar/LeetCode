class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> ans;

        if(nums.size() < 1) {
            return ans;
        }
        
        long long i = 0, expected = nums[0], l = nums[0];

        while(i < nums.size()) {
            if(nums[i] != expected ) {
   
                if (l == nums[i-1]) {
                    ans.push_back(to_string(l));
                } else {
                    ans.push_back(to_string(l) + "->" + to_string(nums[i-1]));    
                }
                expected = nums[i];
                l = nums[i];
            } else {
                expected++;
                i++;
            }
        }

        if (l == nums[i-1]) {
            ans.push_back(to_string(l));
        } else {
            ans.push_back(to_string(l) + "->" + to_string(nums[i-1]));    
        }

        return ans;    
    }
};