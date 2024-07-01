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

 const int N = 1e5 + 10;
class Solution {
public:

    /* My intial solution, gave time limit exceeded error. 

    void calculate_height_for_query(TreeNode* cur, int query, int &ans_height, int cur_height)
    {
        if(cur == NULL)
            return;

        if(cur->val == query) 
            return;
        
        if(ans_height < cur_height) {
            ans_height = cur_height;
        }

        calculate_height_for_query(cur->left, query, ans_height, cur_height + 1);
        calculate_height_for_query(cur->right, query, ans_height, cur_height + 1);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) 
    {
        int n = queries.size();
        vector<int> ans(n, 0);

        for(int i = 0; i < queries.size(); i++) {
            int cur_height = 0;
            calculate_height_for_query(root, queries[i], cur_height, 0);
            ans[i] = cur_height;
        }

        return ans;
    }

    */
    
    /* Dynamic Programming */


    int height(TreeNode* root, unordered_map<int, int> &height_table)
    {
        if(root == NULL)
            return 0;

        height_table[root->val] = max(height(root->left, height_table), height(root->right, height_table)) + 1;
        return height_table[root->val];
    }

    void dfs(TreeNode *cur, TreeNode *parent, TreeNode *peer, int depth, unordered_map<int, int> &all_node_result, unordered_map<int, int> &height_table)
    {
        if(cur == NULL)
            return;

        if(parent == NULL) {
            all_node_result[cur->val] = 0;
        } else {
            all_node_result[cur->val] = max(all_node_result[parent->val], ((peer ? height_table[peer->val] : 0) + depth));
        }

        dfs(cur->left, cur, cur->right, depth + 1, all_node_result, height_table);
        dfs(cur->right, cur, cur->left, depth + 1, all_node_result, height_table);
    }


    vector<int> treeQueries(TreeNode* root, vector<int>& queries) 
    {
        vector<int> ans;

        unordered_map<int, int> height_table;
        unordered_map<int,int> all_node_result;

        height(root, height_table);
        dfs(root, NULL, NULL, -1, all_node_result, height_table);       // using this depth as -1 is really tricky. got it from solution, root node should be treated as depth 0 it seems.
                                                                        // to match that calculation. sending -1 here. In fact still doesnt understand this part.

        for(int i = 0; i < queries.size(); i++) {
            ans.push_back(all_node_result[queries[i]]);
        }

        return ans;
    }

};