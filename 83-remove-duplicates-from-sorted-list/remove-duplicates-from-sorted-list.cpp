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

    /*
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* i = head, *j = head;

        while(j) {
            while ( j && j->val == i->val) {
                j = j->next;
            } 
            i->next = j;
            i = j;
        }
        return head;
    }
    */

    /*
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* i = head, *j = head;

        while(i) {
            while ( j && j->val == i->val) {
                j = j->next;
            } 
            i->next = j;
            i = j;
        }
        return head;
    }
    */

    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode *traverse = head;

        while(traverse && traverse->next) {
            if(traverse->val == traverse->next->val) {
                ListNode *to_delete = traverse->next;
                traverse->next = traverse->next->next;
                delete(to_delete);
            } else {
                traverse = traverse->next;
            }
        }

        return head;
    }

};