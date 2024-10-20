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

    /* Method 1: Using DFS 

    int count_nodes(TreeNode *cur)
    {
        if(cur == NULL)
            return 0;
        
        return 1 + count_nodes(cur->left) + count_nodes(cur->right);
    }

    bool dfs(TreeNode *cur, int index, int n)
    {
        if(cur == NULL)
            return true;
        
        if(index >= n)
            return false;
        
        return dfs(cur->left, 2*index + 1, n) && dfs(cur->right, 2*index + 2, n);
    }

    bool isCompleteTree(TreeNode* root) 
    {
        int n = count_nodes(root);

        return dfs(root, 0, n);    
    }

    */

    /* Method 2: Using BFS */

    bool isCompleteTree(TreeNode* root) 
    {
        if(root == NULL)
            return true;
        
        queue<TreeNode *> q;
        q.push(root);
        bool isNullfound = false;

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();

                if(cur == NULL) {
                    isNullfound = true;
                } else {
                    if(isNullfound == true)
                        return false;
                    
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        return true;
    }
};