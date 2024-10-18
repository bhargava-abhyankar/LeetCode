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

    /* Method 1: Using recursive Inorder 

    void inorder_recursion(TreeNode *cur, int &k, int &ans)
    {
        if(cur == NULL)
            return;
        
        inorder_recursion(cur->left, k, ans);
        k--;
        if(k == 0)
            ans = cur->val;
        inorder_recursion(cur->right, k, ans);
    } 

    int kthSmallest(TreeNode* root, int k) 
    {
        int ans = -1;
        inorder_recursion(root, k, ans);
        return ans;    
    }

    */

    /* Method 2: Using iterative inorder */

    int kthSmallest(TreeNode* root, int k) 
    {
        if(root == NULL)
            return 0;
        
        stack<TreeNode *> st;
        TreeNode *current = root;

        while(current || !st.empty()) {
            while(current) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            k--;
            if(k == 0)
                return current->val;
            current = current->right;
        }

        return 0;
    }
};