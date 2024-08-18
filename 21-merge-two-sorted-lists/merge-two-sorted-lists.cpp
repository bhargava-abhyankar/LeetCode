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

    /* This same template can be used in sorting. using merge sort. know this template very well 

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *dummy = new ListNode(0);
        ListNode *traverse = dummy;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                traverse->next = list1;
                list1 = list1->next;
            } else {
                traverse->next = list2;
                list2 = list2->next;
            }
            traverse = traverse->next;
        }

        while(list1) {
            traverse->next = list1;
            list1 = list1->next;
            traverse = traverse->next;
        }

        while(list2) {
            traverse->next = list2;
            list2 = list2->next;
            traverse = traverse->next;
        }

        return (dummy->next);
    }

    */


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *dummy = new ListNode(-1000, NULL);
        ListNode *traverse = dummy;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                traverse->next = list1;
                list1 = list1->next;
            } else {
                traverse->next = list2;
                list2 = list2->next;
            }
            traverse = traverse->next;
        }

        if(list1) {
            traverse->next = list1;
            traverse = traverse->next;
        }

        if(list2) {
            traverse->next = list2;
            traverse = traverse->next;
        }

        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
};