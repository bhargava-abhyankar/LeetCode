class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> hash;
        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {
            if(hash.find(nums1[i]) == hash.end()) {
                hash.insert({nums1[i], 0});
            }
        }

        for(int i = 0; i< nums2.size(); i++) {
            if(hash.find(nums2[i]) != hash.end()) {
                int t = nums2[i];
                if(hash[t] == 0) {
                    ans.push_back(t);
                    hash[t] = 1;
                }
            }
        }

        return ans;
    }
};