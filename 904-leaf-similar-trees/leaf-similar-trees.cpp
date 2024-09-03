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

    /*Method 1: Simple recursion 

    void pre_order(TreeNode *cur, vector<int>& leaf)
    {
        if(cur == NULL)
            return;
        
        if(cur->left == NULL && cur->right == NULL)
            leaf.push_back(cur->val);

        pre_order(cur->left, leaf);
        pre_order(cur->right, leaf);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> l1, l2;
        pre_order(root1, l1);
        pre_order(root2, l2);
        return(l1 == l2);
    }

    */

    /*Method 2: Best method. Using pre order template */

    int next_leaf(stack<TreeNode *> &s)
    {
        while(!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();

            if(cur->left) { s.push(cur->left); }
            if(cur->right) { s.push(cur->right); }

            if(cur->left == NULL && cur->right == NULL) {
                return cur->val;
            }
        }

        return -1;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        if((root1 && !root2) || (!root1 && root2))
            return false;

        TreeNode *p = root1, *q = root2;

        stack<TreeNode *> st1, st2;
        st1.push(root1);
        st2.push(root2);

        while((!st1.empty()) && !st2.empty()) {
            int node1 = next_leaf(st1);
            int node2 = next_leaf(st2);

            if(node1 != node2) {
                return false;
            }
        }

        return(st1.empty() && st2.empty());   
    }

    
    
};