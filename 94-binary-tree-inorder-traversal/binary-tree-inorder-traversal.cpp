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

    /*
    void print_solution(TreeNode* root, vector<int>& res)
    {
        if(root == NULL)
            return;
        
        print_solution(root->left, res);
        res.push_back(root->val);
        print_solution(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> my_ans;

        print_solution(root, my_ans);
        return my_ans;
    }

    */

    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        TreeNode *current = root;
        stack<TreeNode*> st;

        while(current || !st.empty()) {

            while(current) {
                st.push(current);
                current = current->left;
            }

            ans.push_back(st.top()->val);
            current = st.top()->right;
            st.pop();
        }

        return ans;
    }
};