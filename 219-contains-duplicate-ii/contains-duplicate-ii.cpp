class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int, int> hash;

        for(int i = 0; i < nums.size(); i++) {
            if(hash.find(nums[i]) == hash.end()) {
                hash.insert({nums[i], i});
            } else {
                int j = hash[nums[i]];
                if(abs(j - i) <= k) {
                    return true;
                } else {
                    hash[nums[i]] = i;
                }
            }
        }
        
        return false;
    }
};