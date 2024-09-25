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

    /* Method 1: Using pre order level traversal 

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

    */

    /* Method 2 : Using BFS */

    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> ans;

        if(root == NULL)
            return ans;
        
        double level_sum = 0, level_element = 0;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();

                level_sum = level_sum + cur->val;
                level_element++;

                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            ans.push_back( level_sum/level_element);
            level_sum = 0;
            level_element = 0;
        }

        return ans;
    }
};