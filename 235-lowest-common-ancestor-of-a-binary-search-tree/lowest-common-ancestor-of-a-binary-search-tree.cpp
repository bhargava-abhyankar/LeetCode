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

    /* Method 1: DFS Using recursion based on value of the node

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

    */

    /* Method 2: DFS using iteration based on value of node in BST

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == NULL || p == NULL || q == NULL)
            return NULL;
        
        TreeNode *traverse = root;
        TreeNode *ans = NULL;

        while(traverse) {
            if(p->val < traverse->val && q->val < traverse->val) 
                traverse = traverse->left;
            else if (p->val > traverse->val && q->val > traverse->val)
                traverse = traverse->right;
            else {
                ans = traverse;
                break;
            }
        }
        return ans;
    }

    */

    /* Variation of this problem. Lowest Common ancestor of binary tree, this will work
       for both binary tree and binary search tree */

    TreeNode* postorder(TreeNode* cur, TreeNode* p, TreeNode* q)
    {
        if(cur == NULL)
            return NULL;

        if(cur == p || cur == q)
            return cur;
        
        TreeNode *left = postorder(cur->left, p, q);
        TreeNode *right = postorder(cur->right, p, q);

        if(left && right)
            return cur;
        
        return left ? left:right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode *ans = postorder(root, p, q);
        return ans;
    }
};