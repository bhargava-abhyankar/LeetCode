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
    bool evaluateTree(TreeNode* root) 
    {
        if(root == NULL)
            return false;

        bool a = evaluateTree(root->left);
        bool b = evaluateTree(root->right);    

        if(root->left == NULL && root->right == NULL) {
            return (root->val);
        } else {
            if(root->val == 2) {
                return (a || b);
            } else {
                return (a && b);
            }
        }
    }
};