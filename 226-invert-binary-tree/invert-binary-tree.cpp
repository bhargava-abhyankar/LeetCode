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

    /* Method 1:

    void invert_using_post_order(TreeNode* cur)
    {
        if(cur == NULL) {
            return;
        }

        invert_using_post_order(cur->left);
        invert_using_post_order(cur->right);
        TreeNode *temp = cur->left;
        cur->left = cur->right;
        cur->right = temp;
    }

    TreeNode* invertTree(TreeNode* root) 
    {
        invert_using_post_order(root);
        return root;   
    }

    */

    /* Method 2 */

    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)
            return root;
        
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();

            TreeNode *temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;

            if(cur->left) { 
                q.push(cur->left); 
            } 

            if(cur->right) {
                q.push(cur->right);
            }            
        }

        return root;
    }

};