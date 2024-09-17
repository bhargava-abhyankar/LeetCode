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

    /* method 1: Using pre order recursion as its top down approach 

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

    */

    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();
                level.push_back(cur->val);

                if(cur->left) {
                    q.push(cur->left);
                }

                if(cur->right) {
                    q.push(cur->right);
                }
            }
            ans.push_back(level);
        }

        return ans;
    }
};