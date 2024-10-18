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

    /* Sub optimal method first to do 

    int countNodes(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return(left + right + 1);
    }

    */

    int find_depth(TreeNode *cur)
    {
        int depth = 0;
        
        while(cur->left) {
            depth = depth + 1;
            cur = cur->left;
        }

        return depth;
    }

    bool exists(TreeNode* cur, int d, int index)
    {
        int start = 0, end = pow(2, d) - 1;

        for(int i = 0; i < d; i++) {
            int peviot = (start + end) / 2;

            if(index <= peviot) {
                cur = cur->left;
                end = peviot;
            } else {
                cur = cur->right;
                start = peviot + 1;
            }
        }

        return cur != NULL;
    }

    int countNodes(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        int depth = find_depth(root);

        if(depth == 0)
            return 1;
        
        int start = 1, end = pow(2, depth) - 1;
    
        while(start <= end) {
            int piviot = (end + start) / 2;

            if(exists(root, depth, piviot))
                start = piviot + 1;
            else 
                end = piviot - 1;
        }

        return pow(2, depth) - 1 + start;
    }

};