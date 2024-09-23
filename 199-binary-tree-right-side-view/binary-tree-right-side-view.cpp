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

    void modified_preorder (TreeNode *cur, int level, vector<int> &ans)
    {
        if(cur == NULL)
            return;
        
        if(ans.size() == level)
            ans.push_back(cur->val);

        modified_preorder(cur->right, level + 1, ans);
        modified_preorder(cur->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        modified_preorder(root, 0, ans);
        return ans;
    }
};