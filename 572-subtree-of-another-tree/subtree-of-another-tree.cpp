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

    /* Method 1 : DFS

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL)
            return true;
        if((p && q == NULL) || (p == NULL && q))
            return false;
        if(p->val != q->val)
            return false;

        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root == NULL)
            return false;

        if(isSameTree(root, subRoot)) {
            return true;
        }

        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }

    */

    /* Method 2: BFS and DFS. Not better in time and space, another method */

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if(p == NULL && q == NULL)
            return true;
        if((p && q == NULL) || (p == NULL && q))
            return false;
        if(p->val != q->val) 
            return false;
        
        return(isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *current = q.front();
            q.pop();

            if(isSameTree(current, subRoot)) {
                return true;
            }

            if(current->left)
                q.push(current->left);
            if(current->right)
                q.push(current->right);
        }
        return false;
    }
};