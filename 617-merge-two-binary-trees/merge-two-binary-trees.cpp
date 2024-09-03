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

    /* method 1: My method 

    TreeNode* merge(TreeNode *root1_parent, TreeNode *root2_parent, TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL) {
            return root1;
        } else if (root1 && root2) {
            root1->val = root1->val + root2->val;
        } else if (root1 == NULL && root2 != NULL) {
            TreeNode * new_node = new TreeNode(root2->val);
            if(root2_parent->left == root2) {
                root1_parent->left = new_node;
            } else {
                root1_parent->right = new_node;
            }
            root1 = new_node;
        } else if (root1 && root2 == NULL)
            return root1;

        merge(root1, root2, root1->left, root2->left);
        merge(root1, root2, root1->right, root2->right);
        return root1;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1 == NULL)
            return root2;
        if(root2 == NULL)
            return root1;

        merge(NULL, NULL, root1, root2);
        return root1;
    }

    */

    /* Method 2: Using Iteration */

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        stack<pair<TreeNode*, TreeNode*>> st1; //node, parent
        stack<pair<TreeNode*, TreeNode*>> st2;

        if(root1 == NULL)
            return root2;
        if(root2 == NULL)
            return root1;

        st1.push({root1, NULL});
        st2.push({root2, NULL});

        while(!st2.empty()) {
            TreeNode *p = st1.top().first;
            TreeNode *p_parant = st1.top().second;
            TreeNode *q = st2.top().first;
            TreeNode *q_parent = st2.top().second;
            st1.pop();
            st2.pop();

            p->val = p->val + q->val;

            if(p->left && q->left) {
                st1.push({p->left, p});
                st2.push({q->left, q});
            }

            if(p->right && q->right) {
                st1.push({p->right, p});
                st2.push({q->right, q});
            }

            if(p->left == NULL && q->left) {
                TreeNode *new_node = new TreeNode();
                p->left = new_node;
                st1.push({p->left, p});
                st2.push({q->left, q});
            }

            if(p->right == NULL && q->right) {
                TreeNode *new_node = new TreeNode();
                p->right = new_node;
                st1.push({p->right, p});
                st2.push({q->right, q});
            }
        }

        return root1;
    }
};