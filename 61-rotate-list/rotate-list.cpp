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

    ListNode* rotateRight(ListNode* head, int k) 
    {
        int count = 1;
        ListNode *traverse = head;

        if(!head || head->next == NULL || k == 0)
            return head;

        while(traverse->next) {
            traverse = traverse->next;
            count++;
        }

        traverse->next = head;
        int index = k % count;

        for(int i = 0; i < (count - index); i++) {
            traverse = traverse->next;
        }

        head = traverse->next;
        traverse->next = NULL;
        return head;
    }

};