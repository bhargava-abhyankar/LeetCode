/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    /*Method 1: Using BFS 
   
    Node* connect(Node* root) 
    {
        if(root == NULL) {
            return NULL;
        }

        queue<Node *> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            Node *prev = NULL;

            for(int i = 0; i < size; i++) {
                Node *cur = q.front();
                q.pop();

                if(prev) {
                    prev->next = cur;
                    prev = cur;
                } else {
                    prev = cur;
                }
                
                if(cur->left) {
                    q.push(cur->left);
                }
                if(cur->right) {
                    q.push(cur->right);
                }
            }
        }

        return root;
    }

    */

    /* Method 2: Modified BFS, works only if its perfect binary tree */

    Node* connect(Node* root) 
    {
        if(root == NULL)
            return NULL;
        
        Node *first_left_at_level = root;

        while(first_left_at_level->left) {
            Node *traverse = first_left_at_level;

            while(traverse) {

                traverse->left->next = traverse->right;

                if(traverse->next) {
                    traverse->right->next = traverse->next->left;
                }

                
                traverse = traverse->next;
            }

            first_left_at_level = first_left_at_level->left;
        }

        return root;
    }

};