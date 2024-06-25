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
                        Create two dummy nodes: before and after.
                        Initialize two pointers before_curr and after_curr at the dummy nodes.
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
        if(head == NULL) {
            return NULL;
        }

        ListNode* before_dummy = new ListNode(0);
        ListNode* after_dummy = new ListNode(0);

        ListNode *before_traverse = before_dummy, *after_traverse = after_dummy, *origin = head;

        while(origin) {
            if(origin->val < x) {

                before_traverse->next = origin;
                before_traverse = before_traverse->next;

            } else if (origin->val >= x) {

                after_traverse->next = origin;
                after_traverse = after_traverse->next;

            }

            origin = origin->next;
        }

        before_traverse->next = after_dummy->next;
        after_traverse->next = NULL;
        return (before_dummy->next);
    }
};