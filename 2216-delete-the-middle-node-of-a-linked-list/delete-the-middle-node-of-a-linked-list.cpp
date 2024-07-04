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
    ListNode* deleteMiddle(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode *slow = head, *fast = head->next, *prev = NULL;   

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast == NULL) {                          // middle for if for odd list
            ListNode *temp = prev->next;
            prev->next = temp->next;
            delete(temp);    
        } else if(fast->next == NULL) {             // middle for even list
            ListNode *temp = slow->next;
            slow->next = temp->next;
            delete(temp);
        }

        return head;
    }
};