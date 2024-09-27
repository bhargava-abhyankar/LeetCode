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

    /* Method 1: Using BFS 

    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> ans;

        if(root == NULL)
            return ans;
        
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            long long int max_till_now = LLONG_MIN;

            for(int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();

                max_till_now = max(max_till_now, (long long int)cur->val);

                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            ans.push_back(max_till_now);
        }
        return ans;
    }

    */

    void calculate(TreeNode* cur, int level, vector<vector<int>> &nodes, vector<int>& ans)
    {
        if(cur == NULL)
            return;
        
        if(nodes.size() == level) {
            nodes.push_back(vector<int>());
            nodes[level].push_back(cur->val);
            ans.push_back(cur->val);
        } else {
            nodes[level].push_back(cur->val);
            ans[level] = max(ans[level], cur->val);
        }

        calculate(cur->left, level + 1, nodes, ans);
        calculate(cur->right, level + 1, nodes, ans);
    }

    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> ans;
        vector<vector<int>> nodes;

        calculate(root, 0, nodes, ans);
        return ans;
    }
};