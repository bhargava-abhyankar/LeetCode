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

    bool isEvenOddTree(TreeNode* root) 
    {
        int level = 0;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            int max_till_now = INT_MIN;
            int min_till_now = INT_MAX;

            if(level % 2 == 0) {
                for(int i = 0; i < size; i++) {
                    TreeNode *cur = q.front();
                    q.pop();

                    if(cur->val <= max_till_now || (cur->val %2 != 1)) {
                        return false;
                    }
                    max_till_now = cur->val; 

                    if(cur->left)
                        q.push(cur->left);
                    if(cur->right)
                        q.push(cur->right);
                }
                level++;
            } else {
                for(int i = 0; i < size; i++) {
                    TreeNode *cur = q.front();
                    q.pop();

                    if(cur->val >= min_till_now || (cur->val % 2 != 0))
                        return false;

                    min_till_now = cur->val;

                    if(cur->left)
                        q.push(cur->left);
                    if(cur->right)
                        q.push(cur->right);
                }
                level++;
            }
        }
        return true;
    }

    */

    void check_condition(int val, int level, vector<vector<int>> &nodes, bool &ans)
    {
        int size = nodes[level].size();
        if(level % 2 == 0) {
            if(val % 2 == 0 || (size > 0 && nodes[level][size-1] >= val))
                ans = false;
        } else {
            if(val % 2 == 1 || (size > 0 && nodes[level][size-1] <= val))
                ans = false;
        }
    }

    void checkifevenoddtree(TreeNode* cur, int level, vector<vector<int>> &nodes, bool &ans)
    {
        if(cur == NULL || !ans)
            return;

        if(level == nodes.size()) {            
            nodes.push_back(vector<int>());
        } 

        check_condition(cur->val, level, nodes, ans);
        nodes[level].push_back(cur->val);

        checkifevenoddtree(cur->left, level + 1, nodes, ans);
        checkifevenoddtree(cur->right, level + 1, nodes, ans);    
    }

    bool isEvenOddTree(TreeNode* root) 
    {
        bool ans = true;
        vector<vector<int>> nodes;
        checkifevenoddtree(root, 0, nodes, ans);
        return ans;
    }

};