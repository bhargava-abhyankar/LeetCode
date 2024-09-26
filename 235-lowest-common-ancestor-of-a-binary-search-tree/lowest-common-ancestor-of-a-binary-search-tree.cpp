/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    void recursive_search(TreeNode* cur, TreeNode* p, TreeNode* q, TreeNode* &ans) 
    {
        if(cur == NULL)
            return;
        
        if(ans == NULL && p->val < cur->val && q->val < cur->val)
            recursive_search(cur->left, p, q, ans);
        else if(ans == NULL && p->val > cur->val && q->val > cur->val)
            recursive_search(cur->right, p, q, ans);
        else
            ans = cur;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode *ans = NULL;
        recursive_search(root, p, q, ans);
        return ans;
    }
};