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

    ListNode* swapNodes(ListNode* head, int k) 
    {        
        int count = 0;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *slow = dummy, *fast = dummy, *node_x_prev;

        for(int i = 0; i <= k; i++) {
            if(i == k-1)
                node_x_prev = fast;
            fast = fast->next;
        }

        while(fast) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *node_x = node_x_prev->next, *node_y = slow->next, *node_y_prev = slow;

        if(node_x == NULL || node_y == NULL)
            return head;
        
        if(node_x_prev != NULL) {
            node_x_prev->next = node_y;
        } else {
            dummy->next = node_y;
        }

        if(node_y_prev != NULL) {
            node_y_prev->next = node_x;
        } else {
            dummy->next = node_x;
        }

        ListNode *temp = node_y->next;
        node_y->next = node_x->next;
        node_x->next = temp;

        head = dummy->next;
        return head;
    }


    /*
    ListNode* swapNodes(ListNode* head, int k) 
{
    ListNode *dummy = new ListNode(-1, head);
    ListNode *first_prev = dummy, *second_prev = dummy;
    
    // Find the (k-1)th node (first_prev)
    for(int i = 1; i < k; i++) {
        first_prev = first_prev->next;
    }
    
    ListNode* first = first_prev->next;
    ListNode* fast = first;
    
    while(fast->next) {
        second_prev = second_prev->next;
        fast = fast->next;
    }

    ListNode* second = second_prev->next;

    // If the two nodes to be swapped are the same node, no need to swap
    if (first == second) return head;

    // Swap the nodes by links
    first_prev->next = second;
    second_prev->next = first;

    // Swap the next pointers of the nodes
    ListNode* temp = first->next;
    first->next = second->next;
    second->next = temp;

    return dummy->next;
}

*/



};