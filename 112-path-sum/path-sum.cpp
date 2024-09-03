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

    /* Method 1: using my style of recursion

    void check_if_sum_present(TreeNode *cur, int val, int &target, bool &ans)
    {
        if(cur == NULL)
            return;
        
        val = val + cur->val;

        if(cur->left == NULL && cur->right == NULL) {
            if(val == target)
                ans = true;
        }

        if(!ans)
            check_if_sum_present(cur->left, val, target, ans);
        if(!ans)
            check_if_sum_present(cur->right, val, target, ans);
    } 

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        bool ans = false;
        check_if_sum_present(root, 0, targetSum, ans);
        return ans;
    }

    */

    /* Method 2: 

    bool check_if_sum_present(TreeNode *cur, int val, int &target)
    {
        if(cur == NULL)
            return false;

        val = val + cur->val;

        if(cur->left == NULL && cur->right == NULL) {
            
            if(val == target) {
                return true;
            }
        }

        return (check_if_sum_present(cur->left, val, target) || check_if_sum_present(cur->right, val, target));
    }

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return check_if_sum_present(root, 0, targetSum);
    }

    */

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
            return false;

        int cur_sum = 0;
        stack<pair<TreeNode *, int>> st;
        st.push({root, 0});

        while(!st.empty()) {
            TreeNode *current = st.top().first;
            int cur_sum = st.top().second;
            st.pop();

            cur_sum = cur_sum + current->val;

            if(current->left == NULL && current->right == NULL) {
                if(cur_sum == targetSum)
                    return true;
            }

            if(current->left) 
                st.push({current->left, cur_sum});
            if(current->right)
                st.push({current->right, cur_sum});
        }
        
        return false;

    }

};