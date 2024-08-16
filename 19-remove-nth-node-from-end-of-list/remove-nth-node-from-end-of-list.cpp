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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *fast = head, *slow = head;

        if(!head)
            return head;

        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        if(!fast) {
            head = head->next;
            delete(slow);
            return head;
        }

        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        return head;
    }
    */

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(!head)
            return head;
        
        ListNode *dummy = new ListNode(-1, head);
        ListNode *slow = dummy, *fast = dummy;

        for(int i = 0; i <=n; i++) {
            fast = fast->next;
        }

        while(fast) {
            slow = slow->next;
            fast = fast->next;
        }
    
        ListNode *node_to_delete = slow->next;
        slow->next = slow->next->next;
        head = dummy->next;
        delete(node_to_delete);
        delete(dummy);

        return head;
    }
};