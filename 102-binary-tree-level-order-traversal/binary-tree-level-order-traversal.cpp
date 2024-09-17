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

    void fill_level(TreeNode *cur, int level, vector<vector<int>> &ans)
    {
        if(cur == NULL)
            return;

        if(ans.size() <= level) {
            vector<int> temp;
            temp.push_back(cur->val);
            ans.push_back(temp);
        } else {
            ans[level].push_back(cur->val);
        }

        fill_level(cur->left, level + 1, ans);
        fill_level(cur->right, level + 1, ans);
    }

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        fill_level(root, 0, ans);
        return ans;
    }
};