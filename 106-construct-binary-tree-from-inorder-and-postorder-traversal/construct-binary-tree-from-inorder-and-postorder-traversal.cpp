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

    /* method 1: Using recursion 

    TreeNode* construct_bt(vector<int>& inorder, vector<int>& postorder, int start, int end, int &po_index, 
                            unordered_map<int, int> &hash)
    {
        if(start > end)
            return NULL;
        
        TreeNode *cur = new TreeNode(postorder[po_index]);
        int mid = hash[postorder[po_index]];
        po_index--;

        cur->right = construct_bt(inorder, postorder, mid+1, end, po_index, hash);
        cur->left = construct_bt(inorder, postorder, start, mid-1, po_index, hash);
        
        return cur;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int po_index = postorder.size()-1;
        unordered_map<int, int> hash;

        for(int i = 0; i <inorder.size(); i++) {
            hash[inorder[i]] = i;
        }

        TreeNode *root = construct_bt(inorder, postorder, 0, inorder.size()-1, po_index, hash);
        return root;
    }

    */

    /* Method 2: Using Iteration */

    struct NodeInfo {
        TreeNode *parent;
        int start;
        int end;
        bool isLeft;
    };

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map<int, int> hash;

        for(int i = 0; i < inorder.size(); i++) {
            hash[inorder[i]] = i;
        }

        int postorder_index = postorder.size()-1;
        stack<NodeInfo> st;
        TreeNode *root = new TreeNode(postorder[postorder_index]);
        int start = 0, end = inorder.size()-1, mid = hash[postorder[postorder_index]];
        postorder_index--;

        st.push({root, start, mid-1, true});
        st.push({root, mid+1, end, false});
        
        
        while(!st.empty()) {
            struct NodeInfo info = st.top();
            st.pop();

            start = info.start;
            end = info.end;

            if(start > end)
                continue;

            mid = hash[postorder[postorder_index]];
            TreeNode *cur = new TreeNode(postorder[postorder_index]);
            postorder_index--;

            if(info.isLeft)
                info.parent->left = cur;
            else
                info.parent->right = cur;
            
            st.push({cur, start, mid-1, true});
            st.push({cur, mid+1, end, false});
        }

        return root;
    }
};