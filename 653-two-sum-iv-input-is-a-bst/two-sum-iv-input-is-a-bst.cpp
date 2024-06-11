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

    /*method 1:  
        do inorder traversal and for every node, do target - node value and search
        in tree. Note that while searching, u need to ignore the cur node value. so
        added the check

    void find(TreeNode* root, TreeNode* orig, int rem, bool &ans)
    {
        if(root == NULL)
            return;
        
        if(root->val == rem && root != orig) {
            ans = true;
            return;
        } else if (root->val < rem) {
            find(root->right, orig, rem, ans);
        } else {
            find(root->left, orig, rem, ans);
        }
    }
    void in_order_traverse(TreeNode* root, TreeNode* cur, int k, bool &ans)
    {
        if(cur == NULL)
            return;
        
        in_order_traverse(root, cur->left, k, ans);
        find(root, cur, k - cur->val, ans);
        if(ans == true)
            return;
        in_order_traverse(root, cur->right, k, ans);
    }

    bool findTarget(TreeNode* root, int k) 
    {
        bool ans = false;
        in_order_traverse(root, root, k, ans);
        return ans;
    }
    */

    /* method 2 :  two pointer method */

    void in_order_traverse(TreeNode* cur, vector<int> &nums)
    {
        if(cur == NULL) {
            return;
        }

        in_order_traverse(cur->left, nums);
        nums.push_back(cur->val);
        in_order_traverse(cur->right, nums);

    }

    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> nums;
        in_order_traverse(root, nums);

        int i = 0, j = nums.size()-1;

        while(i < j) {
            if((nums[i] + nums[j]) == k) {
                return true;
            } else if (((nums[i] + nums[j]) > k)) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};