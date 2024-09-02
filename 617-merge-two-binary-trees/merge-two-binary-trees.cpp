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

    TreeNode* merge(TreeNode *root1_parent, TreeNode *root2_parent, TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL) {
            return root1;
        } else if (root1 && root2) {
            root1->val = root1->val + root2->val;
        } else if (root1 == NULL && root2 != NULL) {
            TreeNode * new_node = new TreeNode(root2->val);
            if(root2_parent->left == root2) {
                root1_parent->left = new_node;
            } else {
                root1_parent->right = new_node;
            }
            root1 = new_node;
        } else if (root1 && root2 == NULL)
            return root1;

        merge(root1, root2, root1->left, root2->left);
        merge(root1, root2, root1->right, root2->right);
        return root1;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1 == NULL)
            return root2;
        if(root2 == NULL)
            return root1;

        merge(NULL, NULL, root1, root2);
        return root1;
    }
};