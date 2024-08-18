/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    /*
    Approach: 
            Two Pointer Technique with Dummy Nodes
            The idea is to use two pointers (or references) to create two separate linked lists:

            One for nodes with values less than x
            Another for nodes with values greater than or equal to x
            At the end, we can combine the two linked lists to get the desired result.

    Key Data Structures:
            Linked List: We work directly with the given linked list nodes.
            Dummy Nodes: Two dummy nodes are used to create the starting point for the two partitions.

    Step-by-step Breakdown:
        Initialization:
                        Create two dummy nodes: less_than_list and greater_than_list.
                        Initialize two pointers less_than_traverse and greater_than_traverse at the dummy nodes.
                        Initialize a pointer traverse to head of given list.
        
        Traversal & Partition:
                        Traverse the linked list with the given head.
                        For each node, if its value is less than x, attach it to the before list. Otherwise, attach it to the after list.
        Merging:
                        After traversing the entire list, append the after list to the before list to form the partitioned linked list.

        Result:
                        Return the next node of the before dummy node as the new head of the partitioned list.
    */

    ListNode* partition(ListNode* head, int x) 
    {
        if(!head || head->next == NULL) {
            return head;
        }

        ListNode *less_than_list = new ListNode(-1000, NULL);
        ListNode *greater_than_list = new ListNode(1001, NULL);
        ListNode *less_than_traverse = less_than_list, *greater_than_traverse = greater_than_list, *traverse = head;

        while(traverse) {
            if(traverse->val < x) {
                less_than_traverse->next = traverse;
                less_than_traverse = less_than_traverse->next;
            } else {
                greater_than_traverse->next = traverse;
                greater_than_traverse = greater_than_traverse->next;
            }

            traverse = traverse->next;
        }

        less_than_traverse->next = greater_than_list->next;
        greater_than_traverse->next = NULL;
        head = less_than_list->next;
        delete less_than_list;
        delete greater_than_list;
        return head;
    }
};