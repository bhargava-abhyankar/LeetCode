/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void recursive_serialize(TreeNode* cur, ostringstream &ans)
    {
        if(cur == NULL) {
            ans << "null,";
            return;
        }

        ans << cur->val << ",";
        recursive_serialize(cur->left, ans);
        recursive_serialize(cur->right, ans);
    }
   
    string serialize(TreeNode* root) {
        ostringstream out;
        recursive_serialize(root, out);
        return out.str(); 
    }

    TreeNode* recursive_deserialize(istringstream &input)
    {
        string node;
        getline(input, node, ',');

        if(node == "null")
            return NULL;
    
        TreeNode *cur = new TreeNode(stoi(node));
        cur->left = recursive_deserialize(input);
        cur->right = recursive_deserialize(input);
        return cur;
    }

    TreeNode* deserialize(string data) 
    {
        int index = 0;
        istringstream input(data);

        TreeNode *root = recursive_deserialize(input);
        return root;
    }


};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));