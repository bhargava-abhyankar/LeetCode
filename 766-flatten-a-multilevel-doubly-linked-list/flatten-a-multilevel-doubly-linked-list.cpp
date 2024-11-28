/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* flatten_linked_list(Node *cur)
    {
        Node *traverse = cur, *end = cur;

        while(traverse) {

            if(traverse->child) {
                Node *tail = flatten_linked_list(traverse->child);

                if(traverse->next) {
                    traverse->next->prev = tail;
                }
                    
                tail->next = traverse->next;
                traverse->next = traverse->child;
                traverse->child->prev = traverse;
                traverse->child = NULL;
                traverse = traverse->next;

            } else {
                if(end->next) {
                    end = end->next;
                }
                traverse = traverse->next;
            }
        }

        return end;
    }

    Node* flatten(Node* head) 
    {
        if(head == NULL) {
            return head;
        }

        flatten_linked_list(head);
        return head;
    }
};