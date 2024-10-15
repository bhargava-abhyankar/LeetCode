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

    int recursive_postorder(TreeNode* cur, int &ans)
    {
        if(cur == NULL)
            return 0;
        
        int left = recursive_postorder(cur->left, ans);
        int right = recursive_postorder(cur->right, ans);

        ans = ans + abs(left) + abs(right);
        return (cur->val - 1 + left + right);
    }

    int distributeCoins(TreeNode* root) 
    {
        int ans = 0;
        recursive_postorder(root, ans);
        return ans;
    }
};