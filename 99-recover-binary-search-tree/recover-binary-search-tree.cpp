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

TreeNode* recover_using_inorder(struct TreeNode *root, struct TreeNode *node)
{
    if(node == NULL)
        return root;

    recover_using_inorder(root, node->left);

    if (prev && (prev->val > node->val))
    {
        if(first == NULL)
        {
            first = prev;
            mid = node;
        }
        else if (last == NULL)
        {
            last = node;
        }
    }   
    prev = node;

    recover_using_inorder(root, node->right);
    return root;
}

void recoverTree(TreeNode* root)
{
    root = recover_using_inorder(root, root);
    int temp;
 
    if(first && last)
    {
        temp = first->val;
        first->val = last->val;
        last->val = temp;
    } else if (first && mid)
    {
        temp = first->val;
        first->val = mid->val;
        mid->val = temp;         
    }
}

struct TreeNode *first = NULL;
struct TreeNode *mid = NULL;
struct TreeNode *last = NULL;
struct TreeNode *prev = NULL;

*/


/* Method 1: Using inorder recursion */

void inorder_rec(TreeNode* cur, TreeNode *&x, TreeNode *&y, TreeNode *&prev)
{
    if(cur == NULL)
        return;
    
    inorder_rec(cur->left, x, y, prev);

    if(prev && prev->val > cur->val) {
        y = cur;

        if(x == NULL) {
            x = prev;
        } else {
            return;
        }
    }

    prev = cur;
    inorder_rec(cur->right, x, y, prev);
}

void recoverTree(TreeNode* root)
{
    TreeNode *x = NULL, *y = NULL, *prev = NULL;
    inorder_rec(root, x, y, prev);
    int temp = x->val;
    x->val = y->val;
    y->val = temp;
}

};