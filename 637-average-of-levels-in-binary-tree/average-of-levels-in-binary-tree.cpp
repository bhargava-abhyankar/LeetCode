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

    void calculate(TreeNode *cur, int level, vector<pair<double, double>> &level_data)
    {
        if(cur == NULL)
            return;
        
        if(level == level_data.size()) {
            level_data.push_back({cur->val, 1});
        } else {
            level_data[level].first = level_data[level].first + cur->val;
            level_data[level].second = level_data[level].second + 1;
        }

        calculate(cur->left, level + 1, level_data);
        calculate(cur->right, level + 1, level_data);
    }

    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> ans;
        vector<pair<double, double>> level_data;
        calculate(root, 0, level_data);

        for(int i = 0; i < level_data.size(); i++) {
            ans.push_back (double (((double)level_data[i].first)/ ((double) (level_data[i].second))));
        }

        return ans;    
    }
};