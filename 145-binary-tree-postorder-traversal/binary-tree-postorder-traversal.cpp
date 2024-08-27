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
    void fill_post_order(TreeNode* node, vector<int> &ans)
    {
        if(node == NULL)
            return;

        fill_post_order(node->left, ans);
        fill_post_order(node->right, ans);
        ans.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        fill_post_order(root, ans);
        return ans;    
    }
    */

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        stack<TreeNode *> st1, st2;

        if(!root)
            return ans;
        
        st1.push(root);

        while(!st1.empty()) {
            TreeNode *cur = st1.top();
            st1.pop();
            st2.push(cur);

            if(cur->left)
                st1.push(cur->left);
            if(cur->right)
                st1.push(cur->right);
            
        }

        while(!st2.empty()) {
            TreeNode *current = st2.top();
            st2.pop();
            ans.push_back(current->val);
        }

        return ans;
    }
};