class Solution {
public:

    /* Approach: 

       Create three integer variables left, right and sumOfCurrentWindow. The variables left and right form a subarray by pointing to 
       the starting and ending indices  of the current subarray (or window), and sumOfCurrentWindow stores the sum of this window. 
       Initialize all of them with 0. Create another variable res to store the answer to the problem. We initialize it to a large integer value.
       We iterate over nums using right starting from right = 0 till nums.length - 1 incrementing right by 1 after each iteration.
       We perform the following inside this iteration: Add element at index right to the current window, incrementing sumOfCurrentWindow by nums[right].
       We check if sumOfCurrentWindow >= target. If so, we have a subarray that satisfies our condition. 
       As a result, we attempt to update our answer variable with the length of this subarray. We perform res = min(res, right - left + 1). 
       We then remove the first element from this window by reducing sumOfCurrentWindow by nums[left] and incrementing left by 1. 
       This step is repeated in an inner loop as long as sumOfCurrentWindow >= target. The current window's sum is now smaller than target. 
       We need to add more elements to it. As a result, right is incremented by 1. Return res.

    */

    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int left = 0, right = 0, sum = 0, ans = INT_MAX;

        while(right < nums.size()) {
            sum = sum + nums[right];

            while(sum >= target) {
                ans = min(ans, right-left+1);
                sum = sum - nums[left];
                left++;
            }
            right++;
        }
        return(ans == INT_MAX ? 0 : ans);
    }

};