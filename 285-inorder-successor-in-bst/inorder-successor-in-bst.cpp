/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:


    /* Method 1: Inorder succesor of binary tree 

    void find_inorder_successor(TreeNode* cur, TreeNode* p, TreeNode *&ans, bool &is_found)
    {
        if(cur == NULL)
            return;
        
        if(ans == NULL)
            find_inorder_successor(cur->left, p, ans, is_found);

        if(cur == p) {
            is_found = true;
        } else if(is_found == true && ans == NULL)
            ans = cur;

        if(ans == NULL)
            find_inorder_successor(cur->right, p, ans, is_found);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        bool is_found = false;
        TreeNode *ans = NULL;

        find_inorder_successor(root, p, ans, is_found);
        return ans;
    }

    */

    /* Method 2: Inorder succesor of binary search tree */

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        TreeNode *ans = NULL, *cur = root;

        while(cur) {
            if(cur->val <= p->val) {
                cur = cur->right;
            } else {
                ans = cur;
                cur = cur->left;
            }
        }

        return ans;
    }


};