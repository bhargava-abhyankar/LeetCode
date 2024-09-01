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

    /* Method 1 : this beats 100% 

    bool is_valid (TreeNode* p, TreeNode* q, bool res)
    {

        if(res == false)
        {
            return res;
        }

        if(p != NULL && q != NULL)
        {
            res = is_valid (p->left, q->left, res);
            res = is_valid (p->right, q->right, res);

            if(p->val != q->val)
            {
                return false;
            }

        } else if (p != NULL && q == NULL)
        {
            return false;

        } else if (p == NULL && q != NULL)
        {
            return false;

        } else if (p == NULL && q == NULL)
        {
            return true;
        }

        return res;

    }

    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        return is_valid(p, q, true);   
    }

    */

    /* method 2: using pre order

    void check_if_same(TreeNode* p, TreeNode* q, bool &ans)
    {
        if(p == NULL && q == NULL)
            return;
        
        if((p && q == NULL) || (p == NULL && q) || (p->val != q->val)) {
            ans = false;
            return;
        }

        if (ans == true) { check_if_same(p->left, q->left, ans); }
        if (ans == true) { check_if_same(p->right, q->right, ans); }

    }

    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        bool ans = true;

        check_if_same(p, q, ans);
        return ans;
    }

    */


    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == NULL && q == NULL)
            return true;
        if ((p && q == NULL) || (p == NULL && q != NULL))
            return false;
        if (p->val != q->val)
            return false;

        return(isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }

    /*

    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == NULL && q == NULL)
            return true;

        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});

        while(!st.empty()) {
            TreeNode *tree_one = st.top().first;
            TreeNode *tree_second = st.top().second;
            st.pop();

            if ((tree_one && tree_second && tree_one->val == tree_second->val)) {
                st.push({tree_one->left, tree_second->left});
                st.push({tree_one->right, tree_second->right});
            } else if ((tree_one && tree_second == NULL) || (tree_one == NULL && tree_second) || (tree_one && tree_second && tree_one->val != tree_second->val)) {
                return false;
            }
        }

        return true;
    }
    */
};