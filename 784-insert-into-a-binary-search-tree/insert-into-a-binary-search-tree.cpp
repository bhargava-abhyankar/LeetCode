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

    /* Method 1: Using Iteration 

    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root == NULL) {
            root = new TreeNode(val);
            return root;
        }

        TreeNode *traverse = root;

        while(traverse) {
            if(val < traverse->val) {
                if(traverse->left) {
                    traverse = traverse->left;
                } else {
                    traverse->left = new TreeNode(val);
                    break;
                }
            } else {
                if(traverse->right) {
                    traverse = traverse->right;
                } else {
                    traverse->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
    */

    /* Method 2: Using recursion */


    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root == NULL)
            return new TreeNode(val);
        
        if(val < root->val) {
            root->left = insertIntoBST(root->left, val);
            return root;
        } else {
            root->right = insertIntoBST(root->right, val);
            return root;
        }
    }
};