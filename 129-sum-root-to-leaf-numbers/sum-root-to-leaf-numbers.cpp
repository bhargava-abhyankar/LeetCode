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
    void calculate_sum(TreeNode* node, int cur_sum ,int &final_sum)
    {
        if(node == NULL)
        {
            return;
        }

        if(node->left == NULL && node->right == NULL)
        {
            cur_sum = cur_sum + node->val;

            final_sum = final_sum + cur_sum;
            return;
        }
        cur_sum = cur_sum + node->val;

        calculate_sum(node->left, cur_sum*10, final_sum);
        calculate_sum(node->right, cur_sum*10, final_sum);
    }

    int sumNumbers(TreeNode* root) 
    {
        int final_sum = 0;

        calculate_sum(root, 0, final_sum);
        return final_sum;    
    }

    */

    /* Method 1: Using pre order recursion 

    void calculate(TreeNode *cur, int cur_sum, int &ans)
    {
	    if(cur == NULL) {
		    return;
	    }
	
	    cur_sum = cur_sum * 10 + cur->val;
	
	    if(cur->left == NULL && cur->right == NULL) {
		    ans = ans + cur_sum;
		    return;
	    }
	
	    calculate(cur->left, cur_sum, ans);
	    calculate(cur->right, cur_sum, ans);
    }

    int sumNumbers(TreeNode* root) 
    {
	    int ans = 0;
	
	    calculate(root, 0, ans);
	    return ans;
    }

    */

    /* Method 2: Using Iteration */

    int sumNumbers(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        int ans = 0;
        stack<pair<TreeNode *, int>> st;
        st.push({root, 0});

        while(!st.empty()) {
            TreeNode *cur = st.top().first;
            int cur_sum = st.top().second;
            st.pop();

            cur_sum = cur_sum * 10 + cur->val;

            if(cur->left == NULL && cur->right == NULL) {
                ans = ans + cur_sum;
            }

            if(cur->right) {
                st.push({cur->right, cur_sum});
            }

            if(cur->left) {
                st.push({cur->left, cur_sum});
            }
        }

        return ans;
    }
};