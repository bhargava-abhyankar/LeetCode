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
class BSTIterator {
public:
    vector<int> hash;
    int pos;

    void morris_inorder(TreeNode *current)
    {
        while(current) {
            if (current->left == NULL) {
                hash.push_back(current->val);
                current = current->right;
            } else {
                TreeNode *traverse = current->left;

                while(traverse->right && traverse->right != current) {
                    traverse = traverse->right;
                }

                if(traverse->right == NULL) {
                    traverse->right = current;
                    current = current->left;
                } else {
                    traverse->right = NULL;
                    hash.push_back(current->val);
                    current = current->right;
                }
            }
        }
    }

    BSTIterator(TreeNode* root) {
        hash = vector<int>();
        pos = -1;
        morris_inorder(root);
    }
    
    int next() {
        return hash[++pos];
    }
    
    bool hasNext() {
        return ((pos + 1) < hash.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */