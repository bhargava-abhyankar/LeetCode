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

    bool check_if_bst(TreeNode *cur, TreeNode *&prev)
    {
        if(cur == NULL)
            return true;
        
        if(!check_if_bst(cur->left, prev))
            return false;

        if(prev && prev->val >= cur->val)
            return false;

        prev = cur;
        return check_if_bst(cur->right, prev);
    }

    bool isValidBST(TreeNode* root) 
    {
        TreeNode *prev = NULL;
        return check_if_bst(root, prev);
    }


    /* method 2

    bool isValidBST(TreeNode* root) 
    {
        long prev = LONG_MIN;
        bool ans = true;
        TreeNode *current = root;

        while(current) {
            if(current->left == NULL) {
                int val = current->val;
                if(prev != LONG_MIN && prev >= val) {
                    ans = false;
                }
               
                prev = current->val;
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

                    if(prev != LONG_MIN && prev >= current->val) {
                        ans = false;
                    }
               
                    prev = current->val;
                    current = current->right;   
                }
            }
        }

        return ans;
    }

    */
};