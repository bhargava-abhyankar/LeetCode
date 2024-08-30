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

    int check_if_balanced(TreeNode* root, bool &ans)
    {
        if(root == NULL) {
            return 0;
        }

        int left_sub_height = check_if_balanced(root->left, ans);
        int right_sub_height = check_if_balanced(root->right, ans);

        if((abs(left_sub_height - right_sub_height)) > 1)  {
            ans = false;
        }

        return(1 + max(left_sub_height, right_sub_height));
    }

    bool isBalanced(TreeNode* root) 
    {
        bool ans = true;
        check_if_balanced(root, ans);
        return ans;
    }
};