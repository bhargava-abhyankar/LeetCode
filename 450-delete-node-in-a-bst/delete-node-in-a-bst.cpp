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

    TreeNode* delete_the_node(TreeNode *to_delete, TreeNode *parent, TreeNode *root)
    {
        if(to_delete->left == NULL && to_delete->right == NULL) {
            if(parent == NULL) {
                delete to_delete;
                return NULL;
            }
            if(parent->left == to_delete) {
                delete to_delete;
                parent->left = NULL;
            } else {
                delete to_delete;
                parent->right = NULL;
            }
        } else if (to_delete->left && to_delete->right == NULL) {
            if(parent == NULL) {
                root = to_delete->left;
                delete to_delete;
                return root; 
            }
            if(parent->left == to_delete) {
                parent->left = to_delete->left;
                delete to_delete;
            } else {
                parent->right = to_delete->left;
                delete to_delete;
            }
        } else if (to_delete->right && to_delete->left == NULL) {
            if(parent == NULL) {
                root = to_delete->right;
                delete to_delete;
                return root;
            }
            if(parent->left == to_delete) {
                parent->left = to_delete->right;
                delete to_delete;
            } else {
                parent->right = to_delete->right;
                delete to_delete;
            }
        } else if (to_delete->right && to_delete->left) {
            TreeNode *traverse = to_delete->right;
            while(traverse->left) {
                traverse = traverse->left;
            }
            traverse->left = to_delete->left;

            if(parent == NULL) {
                traverse = to_delete->right;
                delete to_delete;
                return traverse;
            } else {
                if(parent->left == to_delete) {
                    parent->left = to_delete->right;
                } else {
                    parent->right = to_delete->right;
                }
                delete to_delete;
            }
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == NULL)
            return root;
        
        TreeNode *traverse = root, *parent = NULL;

        while(traverse) {
            if(traverse->val == key) {
                root = delete_the_node(traverse, parent, root);
                break;
            } else if (key < traverse->val) {
                parent = traverse;
                traverse = traverse->left;
            } else if (key > traverse->val) {
                parent = traverse;
                traverse = traverse->right;
            }
        }

        return root;
    }
};