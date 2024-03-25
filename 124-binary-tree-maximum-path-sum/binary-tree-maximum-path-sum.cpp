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

    int maximum_path_sum(TreeNode* node, int &ans)
    {
        if(!node)
            return 0;

        int l = max(0, maximum_path_sum(node->left, ans));
        int r = max(0, maximum_path_sum(node->right, ans));
        ans = max(ans, l + r + node->val);
        return (max(l, r) + node->val);

    } 

    int maxPathSum(TreeNode* root) 
    {
        int ans = INT_MIN;
        if(!root)
            return 0;

        maximum_path_sum(root, ans);
        return ans;    
    }
};