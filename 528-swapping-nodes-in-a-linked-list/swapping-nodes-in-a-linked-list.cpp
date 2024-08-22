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

        /* Swap the nodes by links */

        node_x_prev->next = node_y;
        node_y_prev->next = node_x;

        /* Swap the next pointers of the nodes */

        ListNode* temp = node_x->next;
        node_x->next = node_y->next;
        node_y->next = temp;

        head = dummy->next;
        delete(dummy);
        return head;
    }
};