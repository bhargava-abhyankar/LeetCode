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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head || head->next == NULL)
            return head;

        int count = 1;
        ListNode *list1 = new ListNode(0, NULL), *list2 = new ListNode(-1, NULL), *traverse = head;
        ListNode *list1_traverse = list1, *list2_traverse = list2;

        while(traverse) {

            if(count % 2 == 1) {
                list1_traverse->next = traverse;
                list1_traverse = list1_traverse->next;
            } else {
                list2_traverse->next = traverse;
                list2_traverse = list2_traverse->next;
            }

            traverse = traverse->next;
            count++;
        }

        head = list1->next;
        list2_traverse->next = NULL;
        list1_traverse->next = list2->next;

        delete list1;
        delete list2;
        return head;
        
    }
};