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

    /* Method 1: BFS and Hash with sorting 

    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;
        
        queue<pair<TreeNode*, int>> q;
        unordered_map<int, vector<int>> hash;     // if we use map, no need to sort. but every search takes time

        q.push({root, 0});

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode *cur = q.front().first;
                int index = q.front().second;
                q.pop();

                hash[index].push_back(cur->val);

                if(cur->left) {
                    q.push({cur->left, index - 1});
                }
                if(cur->right) {
                    q.push({cur->right, index + 1});
                }
            }
        }

        vector<int> columns;

        for(const auto &pair: hash) {
            columns.push_back(pair.first);
        }

        sort(columns.begin(), columns.end());

        for(auto i : columns) {
            ans.push_back(hash[i]);
        }

        return ans;
    }

    */

    /* Method 2: Using BFS and Hash, without sorting */

    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;
        
        int start = INT_MAX, end = INT_MIN;
        queue<pair<TreeNode *, int>> q;
        unordered_map<int, vector<int>> hash;

        q.push({root, 0});

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode *cur = q.front().first;
                int index = q.front().second;
                q.pop();

                hash[index].push_back(cur->val);
                start = min(start, index);
                end = max(end, index);

                if(cur->left) {
                    q.push({cur->left, index - 1});
                }

                if(cur->right) {
                    q.push({cur->right, index + 1});
                }
            }
        }

        for(int i = start; i <=end; i++) {
            ans.push_back(hash[i]);
        }

        return ans;
    }
};