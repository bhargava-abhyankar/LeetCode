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

    /* Sub optimal method first to do */

    int countNodes(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return(left + right + 1);
    }

    
};