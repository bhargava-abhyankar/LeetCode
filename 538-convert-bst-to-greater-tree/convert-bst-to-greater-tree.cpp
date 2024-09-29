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

    void rec_preorder_for_sum(TreeNode *cur, int &sum)
    {
        if(cur == NULL)
            return;
        
        sum = sum + cur->val;
        rec_preorder_for_sum(cur->left, sum);
        rec_preorder_for_sum(cur->right, sum);
    }

    void rec_inorder(TreeNode *cur, int &sum, int &prev)
    {
        if(cur == NULL)
            return;
        
        rec_inorder(cur->left, sum, prev);
        int temp = cur->val;
        cur->val = sum - prev;
        prev = prev + temp;
        rec_inorder(cur->right, sum, prev);
    }

    TreeNode* convertBST(TreeNode* root) 
    {
        int sum = 0, prev = 0;
        rec_preorder_for_sum(root, sum);
        rec_inorder(root, sum, prev);
        return root;
    }
};