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

    /*

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

    */

    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;

        if(!root)
            return ans;

        TreeNode *current = root;

        while(current) {

            if(current->left == NULL) {
                ans.push_back(current->val);
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
                    ans.push_back(current->val);
                    current = current->right;
                }
            }
        }    

        return ans;    
    }

};