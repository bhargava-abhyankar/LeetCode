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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(!head)
            return head;

        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy, *traverse = head;

        while(traverse) {
            if (traverse->val == val) {
                ListNode *to_delete = traverse;
                prev->next = traverse->next;
                traverse = traverse->next;
                delete(to_delete);
            } else {
                prev = traverse;
                traverse = traverse->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};