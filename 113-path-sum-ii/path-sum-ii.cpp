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

    /* Method 1 : Using recursion */

    bool calculate(TreeNode* cur, int cur_sum, int &targetSum, vector<int> &path, vector<vector<int>> &ans)
    {
        if(cur == NULL)
            return false;

        cur_sum = cur_sum + cur->val;
        path.push_back(cur->val);

        if(cur->left == NULL && cur->right == NULL && cur_sum == targetSum) {
           ans.push_back(path);
        }

        calculate(cur->left, cur_sum, targetSum, path, ans);
        calculate(cur->right, cur_sum, targetSum, path, ans);
        path.pop_back();

        return true;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> path;
        vector<vector<int>> ans;
        calculate(root, 0, targetSum, path, ans);
        return ans;
    }
};