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

    void count_good_nodes(TreeNode* cur, int max_till_now, int& count)
    {
        if(cur == NULL)
            return;

        if(cur->val >= max_till_now) {
            count = count + 1;
            max_till_now = cur->val;
        }

        count_good_nodes(cur->left, max_till_now, count);
        count_good_nodes(cur->right, max_till_now, count);
    }

    int goodNodes(TreeNode* root) 
    {
        int count = 0;
        count_good_nodes(root, INT_MIN, count);
        return count;
    }
};