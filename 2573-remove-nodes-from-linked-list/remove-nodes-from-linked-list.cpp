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
    ListNode* removeNodes(ListNode* head) 
    {
        ListNode *prev = NULL, *cur = head, *next = head;

        while(next) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        int max = INT_MIN;
        head = prev;
        ListNode *traverse = prev, *traverse_prev = prev;

        while(traverse) {
            if(traverse->val < max) {
                ListNode *to_delete = traverse;
                traverse_prev->next = traverse->next;
                traverse = traverse->next;
                delete(to_delete);
            } else {
                max = traverse->val;
                traverse_prev = traverse;
                traverse = traverse->next;
            }
        }

        prev = NULL, cur = head, next = head;

        while(next) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        head = prev;
        return head;
    }
};