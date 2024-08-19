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

    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *dummy = new ListNode(-1000, head);
        ListNode *traverse = head, *prev = dummy;

        while(traverse && traverse->next) {
            if(traverse->val == traverse->next->val) {
                int to_check = traverse->val;

                while(traverse && to_check == traverse->val) {
                    ListNode *to_delete = traverse;
                    traverse = traverse->next;
                    delete(to_delete);
                }

                prev->next = traverse;

            } else {
                prev = prev->next;
                traverse = traverse->next;
            }
        }

        head = dummy->next;
        delete(dummy);
        return head;
    }
};