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

    /* Method 1: Simple Recursion

    void fill_post_order(TreeNode* node, vector<int> &ans)
    {
        if(node == NULL)
            return;

        fill_post_order(node->left, ans);
        fill_post_order(node->right, ans);
        ans.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        fill_post_order(root, ans);
        return ans;    
    }

    */

    /* Method 2: Two stack iteration

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        stack<TreeNode *> st1, st2;

        if(!root)
            return ans;
        
        st1.push(root);

        while(!st1.empty()) {
            TreeNode *cur = st1.top();
            st1.pop();
            st2.push(cur);

            if(cur->left)
                st1.push(cur->left);
            if(cur->right)
                st1.push(cur->right);
            
        }

        while(!st2.empty()) {
            TreeNode *current = st2.top();
            st2.pop();
            ans.push_back(current->val);
        }

        return ans;
    }

    */

    /* Method 3: Single stack iteration */

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> result;          // Vector to store the result in reverse post-order

        if (root == nullptr) return result; // If the tree is empty, return immediately

    stack<TreeNode*> s;          // Stack to hold nodes
    

    s.push(root);

    while (!s.empty()) {
        TreeNode* current = s.top();
        s.pop();
        result.push_back(current->val); // Visit the node

        // Push left and then right to the stack
        if (current->left) {
            s.push(current->left);
        }
        if (current->right) {
            s.push(current->right);
        }
    }

    // Reverse the result to get the correct post-order traversal
    reverse(result.begin(), result.end());
    return result;
    }

    /*
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        stack<TreeNode *> st;
    
        if(!root) {
            return ans;
        }

        TreeNode *current = root;
        TreeNode *last_visited = NULL;

        while(current || !st.empty()) {
            if(current) {
                st.push(current);
                current = current->left;
            } else {
                TreeNode *traverse = st.top();

                if(traverse->right && traverse->right != last_visited) {
                    current = traverse->right;
                } else {
                    ans.push_back(traverse->val);
                    last_visited = traverse;
                    st.pop();
                }
            }
        }

        return ans;
    }

    */

    /* Method 4: Using Morris Traversal

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;

        if(!root)
            return ans;
        
        TreeNode *current = root;

        while(current) {
            if(current->right == NULL) {
                ans.push_back(current->val);
                current = current->left;
            } else {
                TreeNode *traverse = current->right;

                while(traverse->left && traverse->left != current) {
                    traverse = traverse->left;
                }

                if(traverse->left == NULL) {
                    traverse->left = current;
                    ans.push_back(current->val);
                    current = current->right;
                } else {
                    traverse->left = NULL;
                    current = current->left;
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    */
};