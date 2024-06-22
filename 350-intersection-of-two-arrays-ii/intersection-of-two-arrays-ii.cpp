class Solution {
public:
    /*
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        unordered_map<int, int> s1;

        for(int i = 0; i < nums1.size(); i++) {
            if(s1.find(nums1[i]) == s1.end()) {
                s1.insert({nums1[i], 1});        
            } else {
                int t = nums1[i];
                s1[t] = s1[t] + 1;
            }
        }

        for(int i = 0; i < nums2.size(); i++) {
            if (s1.find(nums2[i]) != s1.end()) {
                int t = nums2[i];
                if(s1[t] > 0) {
                    s1[t] = s1[t] - 1;
                    ans.push_back(nums2[i]);
                }
            } 
        }
        return ans;
    }
    */

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;

        while((i < nums1.size()) && (j < nums2.size())) {
            if(nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]){
                i++;
            } else {
                j++;
            }
        }

        return ans;
    }

};