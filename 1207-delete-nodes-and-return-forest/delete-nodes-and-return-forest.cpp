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

    /*Idea is traverse tree and check if that node to be deleted or not. if has to be deleted then delete from original
      and push it children to ans vector as they are new trees. 
      Now we can do it from top to bottom, since if we break the tree and subsequently another element from that tree need
      to be deleted. we dont have mechanism . Hence follow bottom up approach.
      so post order fits the bill. it will process both the childs first. then there is nothing below, we check if its to 
      be delted */

    /*
    void post_order(TreeNode* cur, TreeNode* parent, unordered_set<int> &hash, vector<TreeNode*> &ans)
    {
        if(cur == NULL)
            return;

        post_order(cur->left, cur, hash, ans);
        post_order(cur->right, cur, hash, ans);

        if(hash.find(cur->val) != hash.end()) {
            if(parent && parent->left == cur)              //checking if parent not null for the root case of original tree.
                parent->left = NULL;
            else if(parent && parent->right == cur)
                parent->right = NULL;
            
            if(cur->left)
                ans.push_back(cur->left);
            if(cur->right)
                ans.push_back(cur->right);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        vector<TreeNode*> ans;
        
        if(root == NULL) {
            return ans;
        }

        if(to_delete.size() == 0) {
            ans.push_back(root);
            return ans;
        }

        // Initial intution, failed in root deletetion case. [1,2,3,null,null,null,4] this case.

        ans.push_back(root);                            //original tree has to be in ans, so pushing.
        unordered_set<int> hash;

        for(int i = 0; i < to_delete.size(); i++) {
            hash.insert(to_delete[i]);
        }
        
        post_order(root, NULL, hash, ans);

        return ans;

    }

    */

    TreeNode* post_order(TreeNode *cur, TreeNode *parent, unordered_set<int> &hash, vector<TreeNode*> &ans)
    {
        if(cur == NULL) {
            return NULL;
        }

        post_order(cur->left, cur, hash, ans);
        post_order(cur->right, cur, hash, ans);

        if(hash.find(cur->val) != hash.end()) {

            if(cur->left) {
                ans.push_back(cur->left);
            }
            if(cur->right) {
                ans.push_back(cur->right);
            }

            if(parent) {
                if(parent->left == cur) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
            } else {
                return parent;
            } 
        }

        return cur;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        vector<TreeNode*> ans;

        if(root == NULL)
            return ans;
        
        if(to_delete.size() == 0) {
            ans.push_back(root);
            return ans;
        }

        unordered_set<int> hash;

        for(int i = 0; i < to_delete.size(); i++) {
            hash.insert(to_delete[i]);
        }

        if(post_order(root, NULL, hash, ans)) {
            ans.push_back(root);
        }

        return ans;
    }


};