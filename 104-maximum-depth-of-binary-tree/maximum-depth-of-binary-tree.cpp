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

    /* method 1: counting from top.

    void calculate_max_depth(TreeNode *node, int cur, int &ans)
    {
        if(node == NULL)
            return;
        
        
        cur = cur + 1;
        
        if (node->left == NULL && node->right == NULL)
        {
            if(ans < cur)
            {
                ans = cur;
            }
        }
        calculate_max_depth(node->left, cur, ans);
        calculate_max_depth(node->right, cur, ans);
    }


    int maxDepth(TreeNode* root) 
    {
        int ans = 0;
        calculate_max_depth(root, 0, ans);
        return ans;       
    }

    */

    /* method 2 : counting from bottom */

    int maxDepth(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        int count_from_left_subtree = maxDepth(root->left);               // count of left subtree below current node
        int count_from_right_subtree = maxDepth(root->right);             // count of right subtree below current node

        count_from_left_subtree = count_from_left_subtree + 1;            // add current node to count
        count_from_right_subtree = count_from_right_subtree + 1;          // add current node to count
        return max(count_from_left_subtree, count_from_right_subtree);    // now for the current node, its max among left and right subtree including itself is its height. this is
                                                                          // calculated for all nodes. at last root will have the ans.
    }
};