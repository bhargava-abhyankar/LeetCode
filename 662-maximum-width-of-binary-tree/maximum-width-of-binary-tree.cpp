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
        int ans = 0;

        if(!root)
            return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()) {

            int count = q.size();
            int end = q.back().second; 
            int start = q.front().second;

            ans = max(ans, end-start +1);

            for(int i = 0; i < count; i++) {

                TreeNode* node = q.front().first;
                int n = q.front().second - start;
                q.pop();

                if(node->left != NULL) {
                    q.push({node->left, (long long)2 * n + 1});
                }

                if(node->right != NULL) {
                    q.push({node->right, (long long)2 * n + 2});
                }    
            }
        }

        return ans;
    }
};