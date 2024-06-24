class Solution {
public:

    /* first intution, full wrong 
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = 0, j = 0;

        if(n == 0)
            return;
        
        while(i < m) {
            if(nums1[i] == nums2[j]) {
                i++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                int t = nums1[i];
                nums1[i] = nums2[j];
                nums2[j] = t;
                i++;
            }
        }

        for(int k = 0; k < n; k++) {
            nums1[i] = nums2[k];
            i++;
        }    
    }
    */

    /* Start merging from last using two pointers */

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = m-1, j = n-1, k = m+n-1;

        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
                k--;
            } else if (nums1[i] < nums2[j]) {
                nums1[k] = nums2[j];
                j--;
                k--;
            } else {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
        }
        
        while(j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};