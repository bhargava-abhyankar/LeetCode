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

    /* Method 1 : Using BFS 

    int findBottomLeftValue(TreeNode* root) 
    {
        int ans = 0;
        if(root == NULL)
            return ans;
        
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            ans = q.front()->val;

            for(int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();

                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
        return ans;
    }

    */

    void calculate(TreeNode *cur, int level, vector<int> &ans)
    {
        if(cur == NULL)
            return;
        
        if(ans.size() == level)
            ans.push_back(cur->val);
        
        calculate(cur->left, level + 1, ans);
        calculate(cur->right, level + 1, ans);
    }

    int findBottomLeftValue(TreeNode* root) 
    {
        vector<int> level_first;
        calculate(root, 0, level_first);
        int size = level_first.size();
        return size > 0 ? level_first[size-1]:0;
    }
};