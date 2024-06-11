class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans; 
        unordered_map<int, int> hash_table;

        for(int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];

            if(hash_table.find(rem) != hash_table.end()) {
                ans.push_back(hash_table[rem]);
                ans.push_back(i);
                return ans;
            } else {
               hash_table.insert({nums[i], i});  
            }

        }

        return ans;
    }
};