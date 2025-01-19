class Solution {
public:

    /*
    void traverse_and_find(TreeNode* node, string ans_one, vector<string>& output)
    {
        if(node == NULL)
        {
            return;
        }

        if(node->left == NULL && node->right == NULL)
        {
            ans_one = ans_one + to_string(node->val);
            output.push_back(ans_one);
            return;
        }

        ans_one = ans_one + to_string(node->val) + "->";

        traverse_and_find(node->left, ans_one, output);
        traverse_and_find(node->right, ans_one, output);
    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string one_ans = "";        
        vector<string> output;


        if(root == NULL)
        {
            return output;
        }

        traverse_and_find(root, one_ans, output);
        return output;
    }

    */

    /* Method 1: Better recursion method */

    void all_paths(TreeNode* cur, string cur_path, vector<string> &ans)
    {        
        if(cur->left == NULL && cur->right == NULL) {
            cur_path = cur_path + to_string(cur->val);        
            ans.push_back(cur_path);
            return;
        }

        cur_path = cur_path + to_string(cur->val) + "->";

        if(cur->left)
            all_paths(cur->left, cur_path, ans);
        if(cur->right)
            all_paths(cur->right, cur_path, ans);

        cur_path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ans;
        string cur_path;

        all_paths(root, cur_path, ans);
        return ans;
    }

    /*
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ans;

        if(root == NULL)
            return ans;
        
        stack<pair<TreeNode *, string>> st;
        st.push({root, to_string(root->val)});

        while(!st.empty()) {
            TreeNode *cur = st.top().first;
            string cur_path = st.top().second;
            st.pop();

            if(cur->left == NULL && cur->right == NULL) {
                ans.push_back(cur_path);
                continue;
            }

            if(cur->right) {
                st.push({cur->right, cur_path + "->" + to_string(cur->right->val)});
            }

            if(cur->left) {
                st.push({cur->left, cur_path + "->" + to_string(cur->left->val)});
            }
        }

        return ans;
    }

    */

};