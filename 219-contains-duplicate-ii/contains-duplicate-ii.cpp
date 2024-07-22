class Solution {
public:

    /* My approach: simple hash table.

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

    */

    /* Approach 2: hash table and sliding window */

    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_set<int> hash;

        for(int i = 0; i < nums.size(); i++) {
            if(hash.find(nums[i]) != hash.end()) {
                return true;
            }
            hash.insert(nums[i]);
            if(hash.size() > k) {
                auto itr = hash.find(nums[i-k]);
                hash.erase(itr);
            }
        }
        return false;
    }
};