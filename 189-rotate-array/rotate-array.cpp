class Solution {
public:

    /* brute force method, gives tle during submission 

    void rotate_by_one(vector<int>& nums)
    {
        int n = nums.size();
        int temp = nums[n-1];

        for(int i = n-1; i > 0; i--) {
            nums[i] = nums[i-1];
        }
        nums[0] = temp;
    }

    void rotate(vector<int>& nums, int k) 
    {
        k = k % nums.size();
        
        for(int i = 0; i < k; i++) {
            rotate_by_one(nums);
        }
    }

    */

    /* First reverse entire array, then reverse 0 to k elements and then k to last. */

    void reverse(vector<int>& nums, int i, int j)
    {
        while(i < j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            i++;
            j--;    
        }
    }

    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k = k % nums.size();

        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
};