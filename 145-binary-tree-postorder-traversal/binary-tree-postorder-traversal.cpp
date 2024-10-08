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

    /* Method 3: Single stack iteration with reverse logic

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        stack<TreeNode*> st;

        if(!root)
            return ans;

        TreeNode *current = root;
        st.push(root);

        while(!st.empty()) {
            current = st.top();
            st.pop();
            ans.push_back(current->val);

            if(current->left)
                st.push(current->left);
            if(current->right)
                st.push(current->right);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    */

    /* Method 4: Single stack iteration without reverse 

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        stack<TreeNode *> st;

        if(!root)
            return ans;

        TreeNode* prev = NULL;
        TreeNode *current = root;

        while(current || !st.empty()) {
            if(current) {
                st.push(current);
                current = current->left;
            } else {
                TreeNode *traverse = st.top();

                if(traverse->right && traverse->right != prev) {
                    current = traverse->right;
                } else {
                    ans.push_back(traverse->val);
                    prev = traverse;
                    st.pop();
                }
            }
        }

        return ans;
    }

    */

    /* Method 5: Using Morris Traversal

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

    /* Method 6: One more way, need a better understanding*/

    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(root == NULL)
            return vector<int>();
    
        vector<int> ans;
        unordered_set<TreeNode *> hash;
        stack<TreeNode *> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode *current = st.top();

            if((current->left == nullptr && current->right == nullptr) ||
            (hash.find(current) != hash.end())) {
                ans.push_back(current->val);
                st.pop();
            } else {
                hash.insert(current);

                if(current->right) {
                    st.push(current->right);
                }
                if(current->left) {
                    st.push(current->left);
                }

            }
        }

        return ans;
    }


};