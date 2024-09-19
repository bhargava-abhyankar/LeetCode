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


    /*
    Node* connect(Node* root) 
    {
        int node_count = 0, temp = 0;
        queue<struct Node*> my_queue;
        Node *cur = NULL, *prev = NULL;

        if(root)
        {
            if(root->left)
            {
                my_queue.push(root->left);
                node_count++;
            }
            if(root->right)
            {
                my_queue.push(root->right);
                node_count++;
            }
            root->next = NULL;
        }

        while(!my_queue.empty())
        {
            temp = node_count;
            prev = NULL;

            while(temp)
            {
                cur = my_queue.front();
                
                if(cur->left)
                {
                    my_queue.push(cur->left);
                    node_count++;
                }

                if(cur->right)
                {
                    my_queue.push(cur->right);
                    node_count++;
                }

                if(prev == NULL)
                {
                    prev = cur;
                }
                else
                {
                    prev->next = cur;
                    prev = cur;
                }

                my_queue.pop();
                temp--;
                node_count--;
            }
            cur->next = NULL;
        }

        return root;
    }

    */

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
};