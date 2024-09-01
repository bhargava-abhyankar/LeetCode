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
    void fill_stack(TreeNode* node, stack<int> &my_stack)
    {
        if(node == NULL)
        {
            return;
        }

        fill_stack(node->left, my_stack);
        my_stack.push(node->val);
        fill_stack(node->right, my_stack);
    }

    void check_if_symmetric(TreeNode* node, stack<int> &my_stack, bool &ans)
    {
        if(node == NULL)
            return;
        
        check_if_symmetric(node->left, my_stack, ans);

        if(my_stack.top() != node->val)
        {
            ans = false;
            my_stack.pop();
        }else 
        {
            my_stack.pop();
        }

        check_if_symmetric(node->right, my_stack, ans);
    }

    bool isSymmetric(TreeNode* root) 
    {
        bool ans = true;
        stack<int> my_stack;

        if(root)
        {
            fill_stack(root->left, my_stack);
            check_if_symmetric(root->right, my_stack, ans);
        }
    
        return ans;    
    }

    */

    /* method 1: Using recursion 

    bool check_if_symmetric(TreeNode *p, TreeNode *q)
    {
        if(p == NULL && q == NULL)
            return true;
        if((p && q == NULL) || (p == NULL && q))
            return false;
        if(p->val != q->val)
            return false;
        
        return(check_if_symmetric(p->left, q->right) && check_if_symmetric(p->right, q->left));      
    }

    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
            return true;

        return check_if_symmetric(root->left, root->right);

    }

    */

    /* Method 2. using iterative pre order 

    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
            return true;
        
        stack<pair<TreeNode *, TreeNode *>> st;
        st.push({root->left, root->right});

        while(!st.empty()) {
            TreeNode *p = st.top().first;
            TreeNode *q = st.top().second;
            st.pop();

            if(p && q && p->val == q->val) {
                st.push({p->left, q->right});
                st.push({p->right, q->left});
            } else if ((p && q == NULL) || (p == NULL && q) || (p && q && p->val != q->val)) {
                return false;
            }
        }

        return true;
    }

    */

    /* Method 3: Using BFS */

    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
            return true;
        
        queue<pair<TreeNode *, TreeNode *>> qt;
        qt.push({root->left, root->right});

        while(!qt.empty()) {
            TreeNode *p = qt.front().first;
            TreeNode *q = qt.front().second;
            qt.pop();

            if(p && q && p->val == q->val) {
                qt.push({p->left, q->right});
                qt.push({p->right, q->left});
            } else if ((p && q == NULL) || (p == NULL && q) || (p && q && p->val != q->val)) {
                return false;
            }
        }
        return true;
    }

};