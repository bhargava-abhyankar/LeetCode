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

    /* Method 1: Using Post order serialization 

    string tree2str(TreeNode* root) 
    {
        if(root == NULL)
            return "";

        string left = tree2str(root->left);
        string right =  tree2str(root->right);
        string current = to_string(root->val);

        if(left != "") {
            current = current + "(" + left + ")";
        }

        if(left == "" && right != "") {
            current = current + "()" + "(" + right + ")";
        } else if(right != "") {
            current = current + "(" + right + ")";
        }

        return current;
    }

    */


    string tree2str(TreeNode* root) 
    {
        if(root == NULL)
            return "";

        string result;
        stack<TreeNode *> st;
        TreeNode *current = root, *prev = NULL;

        while(current || !st.empty()) {
            if(current) {
                st.push(current);
                result = result + "(" + to_string(current->val);
                current = current->left;
            } else {
                TreeNode *traverse = st.top();

                if(st.top()->right && st.top()->right != prev) {
                    if (st.top()->left == NULL) {
                        result += "()";  
                    }
                    current = st.top()->right;
                } else {
                    prev = st.top();
                    st.pop();
                    result = result + ")";
                }
            }
        }

        return result.substr(1, result.size() - 2);
    }

};