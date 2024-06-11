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
    void find(TreeNode* root, TreeNode* orig, int rem, bool &ans)
    {
        if(root == NULL)
            return;
        
        if(root->val == rem && root != orig) {
            ans = true;
            return;
        } else if (root->val < rem) {
            find(root->right, orig, rem, ans);
        } else {
            find(root->left, orig, rem, ans);
        }
    }
    void in_order_traverse(TreeNode* root, TreeNode* cur, int k, bool &ans)
    {
        if(cur == NULL)
            return;
        
        in_order_traverse(root, cur->left, k, ans);
        find(root, cur, k - cur->val, ans);
        if(ans == true)
            return;
        in_order_traverse(root, cur->right, k, ans);
    }

    bool findTarget(TreeNode* root, int k) 
    {
        bool ans = false;
        in_order_traverse(root, root, k, ans);
        return ans;
    }
};