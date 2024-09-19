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

    /*

    TreeNode *post_order_flatten(TreeNode *cur)
    {
        if(cur == NULL)
            return NULL;
        
        TreeNode *left = post_order_flatten(cur->left);
        TreeNode *right = post_order_flatten(cur->right);

        if(left) {
            cur->left = NULL;
            cur->right = left;
            TreeNode *temp = cur;
            while(temp->right) {
                temp = temp->right;
            }
            temp->right = right;
        }
        return cur;
    }

    void flatten(TreeNode* root) 
    {
        root = post_order_flatten(root);
    }

    */

    TreeNode *post_order_flatten(TreeNode *cur)
    {
        if(cur == NULL)
            return NULL;

        if(cur->left == NULL && cur->right == NULL)
            return cur;

        TreeNode *left = post_order_flatten(cur->left);
        TreeNode *right = post_order_flatten(cur->right);

        if(left) {
            left->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        return right == NULL ? left: right;
    }

    void flatten(TreeNode* root) 
    {
        root = post_order_flatten(root);
    }

};