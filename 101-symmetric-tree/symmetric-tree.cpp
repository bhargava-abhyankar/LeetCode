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

};