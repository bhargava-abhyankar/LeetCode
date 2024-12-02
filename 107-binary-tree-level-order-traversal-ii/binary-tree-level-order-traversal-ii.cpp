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

    /* Method 1: Using pre order recursion */

    void reverse_level_order(TreeNode* cur, int level, vector<vector<int>> &ans) 
    {
        if(cur == NULL)
            return;
    
        if(ans.size() == level) {
            vector<int> t;
            t.push_back(cur->val);
            ans.insert(ans.begin(), t);
        } else {
            int l = (ans.size()-1) - level;
            ans[l].push_back(cur->val);
        }

        reverse_level_order(cur->left, level + 1, ans);
        reverse_level_order(cur->right, level + 1, ans);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> ans;
        reverse_level_order(root, 0, ans);
        return ans;
    }

    /* Method 2: Using BFS

    vector<vector<int>> levelOrderBottom(TreeNode* root) 
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

            ans.insert(ans.begin(), level);
        }

        return ans;
    }

    */
   
};