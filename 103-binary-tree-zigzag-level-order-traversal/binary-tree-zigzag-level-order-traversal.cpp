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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
    
        if(root == NULL)
            return ans;
        
        bool left_to_right = true;
        deque<TreeNode *> q;
        q.push_back(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> cur_path;

            if(left_to_right) {
                for(int i = 0; i < size; i++) {
                    TreeNode *cur = q.front();
                    q.pop_front();
                    cur_path.push_back(cur->val);

                    if(cur->left)
                        q.push_back(cur->left);
                    if(cur->right)
                        q.push_back(cur->right);
                }
            } else {
                for(int i = 0; i < size; i++) {
                    TreeNode *cur = q.back();
                    q.pop_back();

                    cur_path.push_back(cur->val);

                    if(cur->right)
                        q.push_front(cur->right);
                        
                    if(cur->left)
                        q.push_front(cur->left);
                }
            }
            ans.push_back(cur_path);
            left_to_right = !left_to_right;
        }
        return ans;
    }

    */

    void preorder_level_traversal(TreeNode* cur, int level, vector<vector<int>> &ans)
    {
        if(cur == NULL)
            return;

        if(ans.size() == level) {
            vector<int> temp;
            temp.push_back(cur->val);
            ans.push_back(temp);
        } else {
            if(level % 2 == 0)
                ans[level].push_back(cur->val);
            else {
                ans[level].insert(ans[level].begin(), cur->val);
            }
        }

        preorder_level_traversal(cur->left, level + 1, ans);
        preorder_level_traversal(cur->right, level + 1, ans);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        preorder_level_traversal(root, 0, ans);
        return ans;
    }
};