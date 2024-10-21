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

    /* Method 1: Using Pre order recursion 

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

    */


    /* Method 2: Using BFS */

    string serialize(TreeNode* root) 
    {
        ostringstream ans;

        if(root == NULL)
            return ans.str();
        
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();

                if(cur == NULL) {
                    ans << "null,";
                } else {
                    ans << cur->val << ",";

                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }

        return ans.str();
    }


    TreeNode* deserialize(string data) 
    {
        string node;

        if(data == "")
            return NULL;
    
        istringstream input(data);
        queue<TreeNode *> q;

        getline(input, node, ',');
        TreeNode *root = new TreeNode(stoi(node));
        q.push(root);

        while(!q.empty()) {
            string left_child;
            string right_child;

            getline(input, left_child, ',');
            getline(input, right_child, ',');

            TreeNode *parent = q.front();
            q.pop();

            if(left_child != "null") {
                parent->left = new TreeNode(stoi(left_child));
                q.push(parent->left);
            }

            if(right_child != "null") {
                parent->right = new TreeNode(stoi(right_child));
                q.push(parent->right);
            }
        }

        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));