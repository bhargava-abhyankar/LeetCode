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

    void find_range_sum(TreeNode* cur, int &low, int &high, int &ans)
    {
        if(cur == NULL)
            return;

        if ((cur->val >= low) &&(cur->val <= high))
            ans = ans + cur->val;

        find_range_sum(cur->left, low, high, ans);
        find_range_sum(cur->right, low, high, ans);
    }

    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        int ans = 0;
        find_range_sum(root, low, high, ans);
        return ans;
    }
};