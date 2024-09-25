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

    void all_paths(TreeNode* cur, string cur_path, vector<string> &ans)
    {
        if(cur == NULL)
            return;
        
        if(cur->left == NULL && cur->right == NULL) {
            cur_path = cur_path + to_string(cur->val);        
            ans.push_back(cur_path);
            return;
        }

        cur_path = cur_path + to_string(cur->val) + "->";
        all_paths(cur->left, cur_path, ans);
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
};