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

    /* Method 1: modified pre order recursion 

    void modified_preorder (TreeNode *cur, int level, vector<int> &ans)
    {
        if(cur == NULL)
            return;
        
        if(ans.size() == level)
            ans.push_back(cur->val);

        if(cur->right)
            modified_preorder(cur->right, level + 1, ans);
        if(cur->left)
            modified_preorder(cur->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        modified_preorder(root, 0, ans);
        return ans;
    }

    */

    /* Method 2: Using BFS */

    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;

        if(root == NULL) {
            return ans;
        }

        deque<TreeNode *> dq;
        dq.push_back(root);

        while(!dq.empty()) {
            int size = dq.size();
            ans.push_back(dq.back()->val);

            for(int i = 0; i < size; i++) {
                TreeNode *cur = dq.front();
                dq.pop_front();

                if(cur->left) {
                    dq.push_back(cur->left);
                }

                if(cur->right) {
                    dq.push_back(cur->right);
                }
            }
        }

        return ans;
    }

    
};