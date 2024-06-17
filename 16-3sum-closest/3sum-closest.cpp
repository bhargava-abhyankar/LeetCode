class Solution {
public:

    void calculate_two_sum(vector<int>& nums, int cur_index, int fixed_element, int target, int & closest)
    {
        int i = cur_index, j = nums.size()-1;

        while(i < j) {
            int sum = nums[i] + nums[j] + fixed_element;

            if((abs(sum - target)) < (abs(closest - target))) {
                closest = sum;
            }

            if(sum == target) {
                closest = target;
                return;
            } else if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            }
        }
    }
    int threeSumClosest(vector<int>& nums, int target) 
    {
        if(nums.size() < 3)
            return 0;
        
        int closest = nums[0] + nums[1] + nums[2];  //Initializing to one possible solution,
                                                    // If we do INT_MAX and then do compare after
                                                    // subtraction, while doing subtraction there 
                                                    // can be integer overflow 

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            if(i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            calculate_two_sum(nums, i+1, nums[i], target, closest);
            if(closest == target) {
                return target;
            }
        }

        return closest;
    }
};