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

    /* Method 1: Using indexing and BFS 

    int widthOfBinaryTree(TreeNode* root) 
    {
        long long ans = 0;
        if(root == NULL)
            return 0;
        
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int size = q.size();

            long long start = q.front().second;
            long long end = q.back().second;

            ans = max(ans, (end - start + 1));

            for(int i = 0; i < size; i++) {
                TreeNode *cur = q.front().first;
                long long index = q.front().second - start; // this is just to prevent overflow, otherwise not needed
                q.pop();

                if(cur->left)
                    q.push({cur->left, (long long)2*index + 1});
                if(cur->right)
                    q.push({cur->right, (long long)2*index + 2});
            }
        }

        return ans;
    }

    */

    /* Method 2: Using DFS, pre order level traversal. 
       idea is to store the leftmost or first index of each level. then for all the visits of the nodes,
       node index - first index i.e should be taken from the vector + 1 is compared with existing ans
       variable. 
     */

    void dfs(TreeNode* cur, int level, unsigned long long index, 
             vector<unsigned long long> &level_first_index, unsigned long long &ans)
    {
        if(cur == NULL)
            return;
        
        if(level_first_index.size() == level) {
            level_first_index.push_back(index);
        }

        ans = max(ans, (index - level_first_index[level] + 1));

        dfs(cur->left, level + 1, 2*index +1, level_first_index, ans);
        dfs(cur->right, level + 1, 2*index +2, level_first_index, ans);
    }

    int widthOfBinaryTree(TreeNode* root) 
    {
        unsigned long long ans = 0;
        vector<unsigned long long> level_first_index; // first(leftmost) nodes at each level

        dfs(root, 0, 0, level_first_index, ans);
        return ans;
    }
};