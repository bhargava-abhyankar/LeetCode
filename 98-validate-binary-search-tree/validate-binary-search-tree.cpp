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


    /*
    bool isValidBST(TreeNode* root) 
    {
        long prev = LONG_MIN;
        bool ans = true;
        TreeNode *pred = NULL,*node = root;

        while(node) {
            if(!node->left) {
                int val = node->val;
				
                if (prev != LONG_MIN && prev >= val) {
                    ans = false;
                }

                prev = node->val;
                node = node->right;
            } else {
                pred = node->left;
                
                while(pred->right && pred->right != node) {
                    pred = pred->right;
                }
                
                if(pred->right) {
                    pred->right = nullptr;
					
                    if(prev != LONG_MIN && prev >= node->val) {
                        ans = false;
                    }

                    prev = node->val;
                    node = node->right;
                } else {
                    pred->right = node;
                    node = node->left;
                }
            }
        }

        return ans;
    }
    */
};