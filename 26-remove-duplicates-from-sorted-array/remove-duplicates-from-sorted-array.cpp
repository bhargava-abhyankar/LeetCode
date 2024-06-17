class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        unordered_set<int> hash_table;
        int i =-1, j = 0;

        while(j < nums.size()) {
            if(hash_table.find(nums[j]) == hash_table.end()) {
                hash_table.insert(nums[j]);
                j++;
            } else {
                i = j;
                j++;
                break;
            }
        }

        while(j < nums.size()) {
            if(hash_table.find(nums[j]) == hash_table.end()) {
                hash_table.insert(nums[j]);
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                i++;
                j++;
            }
            else {
                while(j < nums.size() && hash_table.find(nums[j]) != hash_table.end()) {
                    j++;
                }
            }
        }
        return ((i == -1) ? nums.size(): i);       
    }
};