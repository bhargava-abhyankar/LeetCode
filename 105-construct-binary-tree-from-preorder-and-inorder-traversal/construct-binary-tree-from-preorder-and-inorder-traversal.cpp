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

    /*method 1: Using Recursion 

    TreeNode* construct_bt(vector<int>& preorder, vector<int>& inorder, int start, int end, int &pre_order_index, 
                           unordered_map<int, int> &hash)
    {
        if(start > end)
            return NULL;
        
        int root_element = preorder[pre_order_index];
        pre_order_index++;
        TreeNode *node = new TreeNode(root_element);
        int mid = hash[root_element];

        node->left = construct_bt(preorder, inorder, start, mid-1, pre_order_index, hash);
        node->right = construct_bt(preorder, inorder, mid + 1, end, pre_order_index, hash);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int> hash; // number, index;

        for(int i = 0; i < inorder.size(); i++) {
            hash.insert({inorder[i], i});
        }

        int pre_order_index = 0;
        TreeNode *root = construct_bt(preorder, inorder, 0, inorder.size()-1, pre_order_index, hash);
        return root;
    }

    */

    /* Method 2: Using Iteration 

    struct NodeInfo {
        TreeNode *parent;
        int start;
        int end;
        bool isLeft;
    };

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(inorder.size() <= 0)
            return NULL;

        unordered_map<int, int> hash;

        for(int i = 0; i < inorder.size(); i++) {
            hash[inorder[i]] = i;
        }

        stack<NodeInfo> st;
        int start = 0, end = inorder.size()-1, pre_order_index = 0;
        int mid = hash[preorder[pre_order_index]];

        TreeNode *root = new TreeNode(preorder[pre_order_index]);
        pre_order_index++;
        st.push({root, mid+1, end, false});  
        st.push({root, start, mid-1, true});

        while(!st.empty()) {
            struct NodeInfo info = st.top();
            st.pop();
            start = info.start;
            end = info.end;
            
            if(start > end)
                continue;
        
            mid = hash[preorder[pre_order_index]];
            TreeNode *cur = new TreeNode(preorder[pre_order_index]);
            pre_order_index++;

            if(info.isLeft)
                info.parent->left = cur;
            else
                info.parent->right = cur;
            
            st.push({cur, mid+1, end, false});
            st.push({cur, start, mid-1, true});    
        }

        return root;
    }

    */

    int findIndex(const vector<int>& inorder, int start, int end, int key) {
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == key) {
                return i;
            }
        }
        return -1;
    }

    
    TreeNode* buildTreeHelper(const vector<int>& preorder, const vector<int>& inorder, 
                              int& preorderIndex, int inorderStart, int inorderEnd) 
    {
        if (inorderStart > inorderEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preorderIndex]);
        ++preorderIndex;

        if (inorderStart == inorderEnd) {
            return root;
        }

        int inorderIndex = findIndex(inorder, inorderStart, inorderEnd, root->val);
        root->left = buildTreeHelper(preorder, inorder, preorderIndex, inorderStart, inorderIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, preorderIndex, inorderIndex + 1, inorderEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int preorderIndex = 0;
        return buildTreeHelper(preorder, inorder, preorderIndex, 0, inorder.size() - 1);
    }

};