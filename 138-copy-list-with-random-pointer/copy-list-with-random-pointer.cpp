/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> hash;
        Node *new_list = new Node(100000), *new_list_traverse = new_list, *traverse = head;

        while(traverse) {
            new_list_traverse->next = new Node(traverse->val);
            hash[traverse] = new_list_traverse->next;
            new_list_traverse = new_list_traverse->next;
            traverse = traverse->next;
        }

        new_list_traverse = new_list->next;
        traverse = head;

        while(traverse) {
            new_list_traverse->random = hash[traverse->random];
            new_list_traverse = new_list_traverse->next;
            traverse = traverse->next;
        }

        new_list_traverse = new_list->next;
        delete(new_list);
        return new_list_traverse;
    }
};