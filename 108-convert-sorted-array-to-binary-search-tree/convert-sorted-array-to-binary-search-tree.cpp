/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* construct_bst(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return NULL;
        
        int mid = (start + end) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = construct_bst(nums, start, mid-1);
        node->right = construct_bst(nums, mid+1, end);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        TreeNode *root = construct_bst(nums, 0, nums.size()-1);
        return root;
    }
};