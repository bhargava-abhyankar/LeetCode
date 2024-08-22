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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *dummy = new ListNode(-1, head), *traverse = head, *prev = dummy;

        while(traverse && traverse->next) {
            ListNode *node_x = traverse, *node_y_prev = traverse, *node_y = traverse->next;

            prev->next = node_y;
            node_y_prev->next = node_x;

            ListNode *temp = node_x->next;
            node_x->next = node_y->next;
            node_y->next = temp;

            prev = node_x;
            traverse = node_x->next;
        }

        head = dummy->next;
        delete dummy;
        return head;        
    }
};