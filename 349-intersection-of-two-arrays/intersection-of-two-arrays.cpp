class Solution {
public:
    /*
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
    */

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        /*Please note: here u are iterating over set, not orginial vector. Basically
          both set will have unique numbers.  then u iterate over one set and compare it with
          other set. if found put it to ans */
          
        for(const auto &num:s1) {
            if(s2.find(num) != s2.end()) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};