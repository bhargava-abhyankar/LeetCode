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


/* Template for sorting almost sorted Array where Two Elements Are Swapped 

void findTwoSwapped(vector<int> &nums)
{
    int x = -1, y = -1;
    bool isFirstOccurance = false;

    for(int i = 0; i < nums.size()-1; i++) {

        y = i+1;
        if(nums[i] > nums[i+1]) {
            if(isFirstOccurance == false) {
                x = i;
            } else {
                break;
            }
        }
    }

    int temp = nums[x];
    nums[x] = nums[y];
    nums[y] = temp;
}

*/

/* Method 1: Using inorder recursion 

void inorder_rec(TreeNode* cur, TreeNode *&x, TreeNode *&y, TreeNode *&prev)
{
    if(cur == NULL)
        return;
    
    inorder_rec(cur->left, x, y, prev);

    if(prev && prev->val > cur->val) {
        y = cur;

        if(x == NULL) {
            x = prev;
        } else {
            return;
        }
    }

    prev = cur;
    inorder_rec(cur->right, x, y, prev);
}

void recoverTree(TreeNode* root)
{
    TreeNode *x = NULL, *y = NULL, *prev = NULL;
    inorder_rec(root, x, y, prev);
    int temp = x->val;
    x->val = y->val;
    y->val = temp;
}

*/

/* Method 2: Using Inorder iteration */

void recoverTree(TreeNode* root)
{

    TreeNode *x = NULL, *y = NULL, *prev = NULL, *current = root;
    stack<TreeNode *> st;

    while(current || !st.empty()) {
        while(current) {
            st.push(current);
            current = current->left;
        }
    
        current = st.top();
        st.pop();
    
        if(prev && prev->val > current->val) {
            y = current;

            if(x == NULL)
                x = prev;
            else
                break;
        }

        prev = current;
        current = current->right;
    }

    int temp = x->val;
    x->val = y->val;
    y->val = temp;

}


};