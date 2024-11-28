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

    ListNode* reverse_list(ListNode* head, ListNode **tail)
    {
        ListNode *prev = NULL, *cur = head, *next = head;

        while(next) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        *tail = head;
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *traverse = head, *cur_head = head, *cur_tail = NULL, *prev_tail = NULL;
        int count = 1;
        bool is_first = true;

        while(traverse) {

            if(count == k) {
                ListNode *temp = traverse;
                traverse = traverse->next;
                temp->next = NULL;

                cur_head = reverse_list(cur_head, &cur_tail);
            
                if(is_first) {
                    is_first = false;
                    head = cur_head;
                } else {
                    prev_tail->next = cur_head;
                }

                prev_tail = cur_tail;

                count = 1;
                cur_head = traverse;
                cur_tail = NULL;

            } else {
                count++;
                traverse = traverse->next;
            }
        }

        if(prev_tail) {
            prev_tail->next = cur_head;
        }

        return head;
    }

};