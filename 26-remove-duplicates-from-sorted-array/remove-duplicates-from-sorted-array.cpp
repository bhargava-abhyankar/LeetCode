class Solution {
public:
    /*
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
    */

    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size() < 1) {
            return 0;    
        }

        int i = 0, j = 1;

        while(j < nums.size()) {
            if(nums[j] == nums[i]) {
                j++;
            } else {
                nums[i+1] = nums[j];
                i++;
                j++;
            }
        }
        return (i+1);
    }
};