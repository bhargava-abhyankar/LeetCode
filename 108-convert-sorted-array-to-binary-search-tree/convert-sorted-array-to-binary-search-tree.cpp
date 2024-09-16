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

    /* Method 1: Always Choose Left Middle Node as a Root

    TreeNode* construct_bst(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return NULL;
        
        int mid = (start + end) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = construct_bst(nums, start, mid-1);
        node->right = construct_bst(nums, mid+1, end);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        TreeNode *root = construct_bst(nums, 0, nums.size()-1);
        return root;
    }

    */

    /* Method 2: Always Choose right Middle Node as a Root 

    TreeNode* construct_bst(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return NULL;

        int mid = (start + end) / 2;
        if (((start + end) % 2) == 1) {
            mid = mid + 1;
        }

        TreeNode *node = new TreeNode(nums[mid]);
        node->left = construct_bst(nums, start, mid-1);
        node->right = construct_bst(nums, mid+1, end);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        TreeNode *root = construct_bst(nums, 0, nums.size()-1);
        return root;
    }

    */

    /* Method 3: Using iteration */

    struct NodeInfo {
        TreeNode *parent;
        int start;
        int end;
        bool isLeft;       //flag to know if current node belong to left of parent or right
    };

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.size() <= 0)
            return NULL;
        
        stack<NodeInfo> st;
        int start = 0, end = nums.size()-1;
        int mid = (start + end) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        st.push({root, 0, mid - 1, true});
        st.push({root, mid + 1, end, false});

        while(!st.empty()) {
            struct NodeInfo cur_nodeinfo = st.top(); 
            st.pop();
            start = cur_nodeinfo.start;
            end = cur_nodeinfo.end;
            mid = (start + end)/2;

            if(start > end)
                continue;
            
            TreeNode *new_node = new TreeNode(nums[mid]);

            if(cur_nodeinfo.isLeft) {
                cur_nodeinfo.parent->left = new_node;
            } else {
                cur_nodeinfo.parent->right = new_node;
            }

            st.push({new_node, start, mid-1, true});
            st.push({new_node, mid+1, end, false});
        }

        return root;
    }
};