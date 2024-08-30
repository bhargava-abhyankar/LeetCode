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
    int diameter(TreeNode* root, int &ans) 
    {
        if(root == NULL) {
            return 0;
        }

        int left_max = diameter(root->left, ans);
        int right_max = diameter(root->right, ans);

        ans = max(ans, left_max + right_max);

        return (1 + max(left_max, right_max));
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        int ans = 0;

        if(root == NULL)
            return ans;
        
        diameter(root, ans);
        return ans;
    }
};