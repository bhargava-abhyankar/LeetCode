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

    /* Method 1: using inorder prev. 
    
    void recursive_in_order(TreeNode* cur, TreeNode* &prev, int &ans)
    {
        if(cur == NULL)
            return;
    
        recursive_in_order(cur->left, prev, ans);
        if(prev)
            ans = min(ans, (cur->val - prev->val));

        prev = cur;
        recursive_in_order(cur->right, prev, ans);
    } 

    int minDiffInBST(TreeNode* root) 
    {
        int ans = INT_MAX;
        TreeNode *prev = NULL;
        recursive_in_order(root, prev, ans);    
        return ans;
    }
    */

    /* Method 2: Morris Traversal */

    int minDiffInBST(TreeNode* root) 
    {
        if(root == NULL)
            return 0;

        int ans = INT_MAX;
        TreeNode *current = root, *prev = NULL;

        while(current != NULL) {
            if(current->left == NULL) {
                if(prev) {
                    ans = min(ans, current->val - prev->val);
                }
                prev = current;
                current = current->right;
            } else {
                TreeNode *traverse = current->left;
                while(traverse->right && traverse->right != current) {
                    traverse = traverse->right;
                }

                if(traverse->right == NULL) {
                    traverse->right = current;
                    current = current->left;
                } else {
                    traverse->right = NULL;
                    
                    if(prev) {
                        ans = min(ans, current->val - prev->val);
                    }
                    prev = current;
                    current = current->right;
                }
            }
        }

        return ans;
    }
};