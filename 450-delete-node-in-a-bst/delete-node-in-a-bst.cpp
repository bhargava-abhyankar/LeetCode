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

    /* Method 1: Using Iteration 

    TreeNode* delete_the_node(TreeNode *to_delete, TreeNode *parent, TreeNode *root)
    {
        TreeNode *child = NULL;

        if (to_delete->left && to_delete->right == NULL) {
            child = to_delete->left;
        } else if (to_delete->right && to_delete->left == NULL) {
            child = to_delete->right;
        } else if (to_delete->left && to_delete->right == NULL) {
            child = to_delete->left;
        } else if (to_delete->left && to_delete->right) {

            TreeNode *traverse = to_delete->right;

            while(traverse->left) {
                traverse = traverse->left;
            }
            traverse->left = to_delete->left;

            if(parent == NULL) {
                traverse = to_delete->right;
                root = traverse;
                delete to_delete;
            } else {
                if(parent->left == to_delete) {
                    parent->left = to_delete->right;
                } else {
                    parent->right = to_delete->right;
                }
                delete to_delete;
            }
            return root;
        }

        if(parent) {
            if(parent->left == to_delete)
                parent->left = child;
            else
                parent->right = child;
        } else {
            root = child;
        }

        delete to_delete;
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

    */

    /* Using recursion */

    TreeNode* bstdelete(TreeNode *cur, TreeNode *parent, int &key)
    {
        if(cur == NULL)
            return cur;
        
        if(key < cur->val) {
            cur->left = bstdelete(cur->left, cur, key);
        } else if (key > cur->val) {
            cur->right = bstdelete(cur->right, cur, key);
        } else {
            TreeNode *child = NULL;

            if(cur->left == NULL && cur->right == NULL) {
                child = NULL;
            } else if (cur->left && cur->right == NULL) {
                child = cur->left;
            } else if (cur->right && cur->left == NULL) {
                child = cur->right;
            } else if (cur->left && cur->right) {
                TreeNode *traverse = cur->right;

                while(traverse->left)
                    traverse = traverse->left;
                
                traverse->left = cur->left;
                child = cur->right;
            }

            delete cur;
            return child;
        }
        return cur;
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        root = bstdelete(root, NULL, key);
        return root;
    }
};