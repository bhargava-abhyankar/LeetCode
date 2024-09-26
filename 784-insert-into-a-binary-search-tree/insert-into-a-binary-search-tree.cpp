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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root == NULL) {
            root = new TreeNode(val);
            return root;
        }

        TreeNode *traverse = root, *parent = NULL;

        while(traverse) {
            if(val < traverse->val) {
                parent = traverse;
                traverse = traverse->left;
            } else {
                parent = traverse;
                traverse = traverse->right;
            }
        }

        if(val < parent->val)
            parent->left = new TreeNode(val);
        else 
            parent->right = new TreeNode(val);
        
        return root;
    }
};