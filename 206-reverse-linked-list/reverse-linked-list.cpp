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

    /* Iterative

    ListNode* reverseList(ListNode* head) 
    {
        if(!head)
            return head;
        
        ListNode *prev = NULL, *cur = head, *next = head;

        while(next) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    */

    void reverse_recursive(ListNode* prev, ListNode* cur, ListNode** head)
    {
        if(cur == NULL) {
            *head = prev;
            return;
        }

        ListNode *next = cur->next;
        cur->next = prev;

        reverse_recursive(cur, next, head);
    }

    ListNode* reverseList(ListNode* head) 
    {
        reverse_recursive(NULL, head, &head);
        return head;
    }

};