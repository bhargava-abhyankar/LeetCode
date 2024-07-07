class Solution {
public:

    /* Method 1: Using hash_table. time and space complexity both are O(n) and O(n) 

    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        unordered_map<int, int> hash;         //number and index

        for(int i = 0; i < nums.size(); i++) {
            int t = target-nums[i];

            if(hash.find(t) != hash.end()) {
                ans.push_back(i);
                ans.push_back(hash[t]);
                return ans;

            } else {
                hash.insert({nums[i], i});
            }
        }

        return ans;
    }

    */

    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        return( a.first < b.first);
    }

    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        vector<pair<int, int>> num_array;

        for(int i = 0; i < nums.size(); i++) {
            num_array.push_back({nums[i], i});
        }

        sort(num_array.begin(), num_array.end(), comp);

        int i = 0, j = num_array.size()-1;

        while(i < j) {
            if( (num_array[i].first + num_array[j].first) == target) {
                ans.push_back(num_array[i].second);
                ans.push_back(num_array[j].second);
                return ans;
            } else if ((num_array[i].first + num_array[j].first) > target) {
                j--;
            } else if ((num_array[i].first + num_array[j].first) < target) {
                i++;
            }
        }

        return ans;
    }
};