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

    string find(TreeNode *cur, vector<TreeNode *>&ans, 
                unordered_map<string, int> &hash)
    {
        if(cur == NULL)
            return "#";
        
        string left = find(cur->left, ans, hash);
        string right = find(cur->right, ans, hash);

        string current_string = left + "," + right + "," + to_string(cur->val);
        if(hash[current_string] == 1)
            ans.push_back(cur);
        
        hash[current_string]++;
        
        return current_string;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        vector<TreeNode *> ans;
        unordered_map<string, int> hash;
        find(root, ans, hash);
        return ans;
    }
};