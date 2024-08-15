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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int sum = 0, carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;

        while(l1 && l2) {
            sum = (carry + l1->val + l2->val) % 10;
            carry = (carry + l1->val + l2->val) / 10;

            prev->next = new ListNode(sum);
            prev = prev->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            sum = (carry + l1->val) % 10;
            carry = (carry + l1->val) / 10;
            prev->next = new ListNode(sum);
            prev = prev->next;
            l1 = l1->next;
        }

        while(l2) {
            sum = (carry + l2->val) % 10;
            carry = (carry + l2->val) / 10;
            prev->next = new ListNode(sum);
            prev = prev->next;
            l2 = l2->next;
        }

        if(carry) {
            prev->next = new ListNode(carry);
            prev = prev->next;
        }

        prev = dummy->next;
        delete dummy;
        return prev;
    }
};