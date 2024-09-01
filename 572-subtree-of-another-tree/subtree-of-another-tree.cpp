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

    /* Method 2: BFS and DFS.  another method 

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

    */

    /* Method 3:  Optimized Method */

    void serialize(TreeNode *cur, stringstream &s)
    {
        if(cur == NULL) {
            s << ",#";
            return;
        }

        s << "," << cur->val;
        serialize(cur->left, s);
        serialize(cur->right, s);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        stringstream rootstream;
        stringstream subrootstram;

        serialize(root, rootstream);
        serialize(subRoot, subrootstram);

        string root_string = rootstream.str();
        string subroot_string = subrootstram.str();

        return (root_string.find(subroot_string) != string::npos);
    }

};