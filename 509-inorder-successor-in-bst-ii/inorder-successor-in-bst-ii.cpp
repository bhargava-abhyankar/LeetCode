/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:


    Node* inorderSuccessor(Node* node) 
    {
        Node* ans = NULL, *cur = node;

        if(cur->right) {
            Node *temp = cur->right;

            while(temp->left) {
                temp = temp->left;
            }
            return temp;

        } else {
            Node *parent = cur->parent;

            while(parent) {
                if(cur == parent->left) {
                    ans = parent;
                    return ans;
                } else {
                    cur = parent;
                    parent = parent->parent; 
                }
            }
        }
        
        return NULL;
    }

};