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
    int widthOfBinaryTree(TreeNode* root) 
    {
        long long ans = 0;
        if(root == NULL)
            return 0;
        
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int size = q.size();

            long long start = q.front().second;
            long long end = q.back().second;

            ans = max(ans, (end - start + 1));

            for(int i = 0; i < size; i++) {
                TreeNode *cur = q.front().first;
                long long index = q.front().second - start; // this is just to prevent overflow, otherwise not needed
                q.pop();

                if(cur->left)
                    q.push({cur->left, (long long)2*index + 1});
                if(cur->right)
                    q.push({cur->right, (long long)2*index + 2});
            }
        }

        return ans;
    }
};