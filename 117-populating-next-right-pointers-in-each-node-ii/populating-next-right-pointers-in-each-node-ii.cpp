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


    Node* connect(Node* root) 
    {
        if(root == NULL)
            return root;
        
        Node *current = root;
        Node *next_level = new Node(-1000);
        Node *prev = next_level;

        while(current) {
            while(current) {
                if(current->left) {
                    prev->next = current->left;
                    prev = prev->next;
                }

                if(current->right) {
                    prev->next = current->right;
                    prev = prev->next;
                }

                current = current->next;
            }

            current = next_level->next;
            next_level->next = NULL;
            prev = next_level;
        }

        delete next_level;
        return root;
    }
};