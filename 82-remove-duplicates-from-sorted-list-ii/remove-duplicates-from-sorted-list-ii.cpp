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

    /* Use dummy node, initialize cur to head and next to cur->next. maintain a flag to see for duplicity */
    
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy, *cur = head;
        dummy->next = head;

        while(cur) 
        {
            ListNode *next = cur->next;
            bool is_duplicate = false;

            while(next && cur->val == next->val) {
                is_duplicate = true;
                next = next->next;
            }

            if(is_duplicate) {
                prev->next = next;
            } else {
                prev = cur;
            }
            cur = next;   
        }

        return dummy->next;
    }
};