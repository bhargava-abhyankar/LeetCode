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
    void fill_pre_order(TreeNode *node, vector<int> &ans)
    {
        if(node == NULL)
            return;
        
        ans.push_back(node->val);
        fill_pre_order(node->left, ans);
        fill_pre_order(node->right, ans);

    }

    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;

        fill_pre_order(root, ans);
        return ans;    
    }
    */

    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        stack<TreeNode*> st;

        if(!root)
            return ans;

        st.push(root);

        while(!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            ans.push_back(cur->val);

            if(cur->right) 
                st.push(cur->right);
            if(cur->left)
                st.push(cur->left);
        }

        return ans;
    }
};