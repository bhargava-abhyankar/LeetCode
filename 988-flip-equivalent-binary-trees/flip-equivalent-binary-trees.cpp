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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        if(root1 == root2)
            return true;
        if ((root1 && root2 == NULL ) || (root1 == NULL && root2) || (root1->val != root2->val))
            return false;
        
        queue<pair<TreeNode *, TreeNode *>> q;
        q.push({root1, root2});

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode *cur1 = q.front().first;
                TreeNode *cur2 = q.front().second;
                q.pop();

                if(cur1->val != cur2->val)
                    return false;
                
                TreeNode *left1 = cur1->left, *right1 = cur1->right;
                TreeNode *left2 = cur2->left, *right2 = cur2->right;

                bool no_flip = (((left1 == left2) || (left1 && left2 && left1->val == left2->val)) 
                                && ((right1 == right2) || (right1 && right2 && right1->val == right2->val)));
                bool flip = (((left1 == right2) || (left1 && right2 && left1->val == right2->val)) && 
                            ((right1 == left2) || (right1 && left2 && right1->val == left2->val)));

                if(!no_flip && !flip)
                    return false;
                
                if(no_flip) {
                    if(left1)
                        q.push({left1, left2});
                    if(right1)
                        q.push({right1, right2});
                } else {
                    if(right1)
                        q.push({right1, left2});
                    if(left1)
                        q.push({left1, right2});
                }
            }
        }

        return true;
    }
};