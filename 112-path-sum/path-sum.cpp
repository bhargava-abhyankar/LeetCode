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

    bool check_if_sum_present(TreeNode *cur, int val, int &target)
    {
        if(cur == NULL)
            return false;

        val = val + cur->val;

        if(cur->left == NULL && cur->right == NULL) {
            
            if(val == target) {
                return true;
            }
        }

        return (check_if_sum_present(cur->left, val, target) || check_if_sum_present(cur->right, val, target));
    }

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return check_if_sum_present(root, 0, targetSum);
    }
};