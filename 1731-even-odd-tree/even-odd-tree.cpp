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
};