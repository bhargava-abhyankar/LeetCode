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

    /*Method 1: simple two pass solution. time complexity O(n) and space complexity O(n)

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

    */

    Node* copyRandomList(Node* head) 
    {
        Node *traverse = head, *new_node = NULL;

        while(traverse) {
            new_node = new Node(traverse->val);
            new_node->next = traverse->next;
            traverse->next = new_node;
            traverse = new_node->next;
        }

        traverse = head;

        while(traverse) {
            new_node = traverse->next;
            if(traverse->random)
                new_node->random = traverse->random->next;
            else
                new_node->random = NULL;
            traverse = new_node->next;
        }

        traverse = head;
        
        Node* new_list = new Node(10000);
        new_node = new_list;
        
        while(traverse) {
            new_node->next = traverse->next;
            traverse->next = traverse->next->next;
            
            new_node = new_node->next;
            traverse = traverse->next;
        }

        return new_list->next;

    }
};