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

    /* Method 1: using recursion 

    bool evaluateTree(TreeNode* root) 
    {
        if(root == NULL)
            return false;

        bool a = evaluateTree(root->left);
        bool b = evaluateTree(root->right);    

        if(root->left == NULL && root->right == NULL) {
            return (root->val);
        } else {
            if(root->val == 2) {
                return (a || b);
            } else {
                return (a && b);
            }
        }
    }

    */

    /* Method 2: using iteration 

    bool evaluateTree(TreeNode* root) 
    {
        if(root == NULL)
            return false;
    
        stack<TreeNode *> st1, st2;
        st1.push(root);

        while(!st1.empty()) {
            TreeNode *current = st1.top();
            st1.pop();
            st2.push(current);

            if(current->left)
                st1.push(current->left);
            if(current->right)
                st1.push(current->right);
        }

        while(!st2.empty()) {
            TreeNode *cur = st2.top();
            st2.pop();

            if(cur->left == NULL && cur->right == NULL)
                continue;

            bool a = false, b = false;
            if(cur->left)
                a = cur->left->val;
            if(cur->right)
                b = cur->right->val;
            
            if(cur->val == 2) {
                cur->val = (a || b);
            } else {
                cur->val = (a && b);
            }
        }

        return root->val;
    }

    */

    bool evaluateTree(TreeNode* root)
{
	if(root == NULL)
		return false;
	
	if(root->left == NULL && root->right == NULL) {
		return root->val;
	}
	
	bool left = evaluateTree(root->left);
	bool right = evaluateTree(root->right);
	
	if(root->val == 2) {
		return left || right; 
	} else {
		return left && right;
	}

}
};