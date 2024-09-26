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
};