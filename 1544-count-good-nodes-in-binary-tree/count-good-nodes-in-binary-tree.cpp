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

    /* Method 1: Using pre order recursion 

    void count_good_nodes(TreeNode* cur, int max_till_now, int& count)
    {
        if(cur == NULL)
            return;

        if(cur->val >= max_till_now) {
            count = count + 1;
            max_till_now = cur->val;
        }

        count_good_nodes(cur->left, max_till_now, count);
        count_good_nodes(cur->right, max_till_now, count);
    }

    int goodNodes(TreeNode* root) 
    {
        int count = 0;
        count_good_nodes(root, INT_MIN, count);
        return count;
    }

    */

    /* Method 2: Using pre order iteration

    int goodNodes(TreeNode* root) 
    {
        if(root == NULL)
            return 0;

        int count = 0;
        stack<pair<TreeNode *, int>> st;
        st.push({root, INT_MIN});

        while(!st.empty()) {
            TreeNode *current = st.top().first;
            int max_till_now = st.top().second;
            st.pop();

            if(current->val >= max_till_now) {
                count++;
                max_till_now = current->val;
            }

            if(current->right) {
                st.push({current->right, max_till_now});
            }

            if(current->left) {
                st.push({current->left, max_till_now});
            }

        }

        return count;
    }

    */

    /*Method 3: Using BFS. */

    int goodNodes(TreeNode* root) 
    {
        if(root == NULL)
            return 0;

        int count = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, INT_MIN});

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode *cur = q.front().first;
                int max_till_now = q.front().second;
                q.pop();

                if(cur->val >= max_till_now) {
                    count++;
                    max_till_now = cur->val;
                }

                if(cur->left)
                    q.push({cur->left, max_till_now});
                if(cur->right)
                    q.push({cur->right, max_till_now});
            }
        }
        return count;
    }
};