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

    /* Method 1: Using BFS */

    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans;

        if (!root) 
            return ans;

        map<int, vector<pair<int, int>>> hash;
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {vertical, level}}

        q.push({root, {0, 0}});

        while (!q.empty()) {
            TreeNode *node = q.front().first;
            int vertical = q.front().second.first;
            int level = q.front().second.second;
            q.pop();

            hash[vertical].emplace_back(level, node->val);

            if (node->left) 
                q.push({node->left, {vertical - 1, level + 1}});

            if (node->right) 
                q.push({node->right, {vertical + 1, level + 1}});
        }

        for (auto& entry : hash) {
            sort(entry.second.begin(), entry.second.end()); // Sort by level, then by value

            vector<int> col;
            for (auto& p : entry.second) {
                col.push_back(p.second); // Collect only the values
            }
            ans.push_back(col); // Add to the final result
        }

        return ans;
    }
    
};