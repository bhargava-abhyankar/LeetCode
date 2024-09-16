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

    TreeNode* construct_bt(vector<int>& preorder, vector<int>& inorder, int start, int end, int &pre_order_index, 
                           unordered_map<int, int> &hash)
    {
        if(start > end)
            return NULL;
        
        int root_element = preorder[pre_order_index];
        pre_order_index++;
        TreeNode *node = new TreeNode(root_element);
        int mid = hash[root_element];

        node->left = construct_bt(preorder, inorder, start, mid-1, pre_order_index, hash);
        node->right = construct_bt(preorder, inorder, mid + 1, end, pre_order_index, hash);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int> hash; // number, index;

        for(int i = 0; i < inorder.size(); i++) {
            hash.insert({inorder[i], i});
        }

        int pre_order_index = 0;
        TreeNode *root = construct_bt(preorder, inorder, 0, inorder.size()-1, pre_order_index, hash);
        return root;
    }
};