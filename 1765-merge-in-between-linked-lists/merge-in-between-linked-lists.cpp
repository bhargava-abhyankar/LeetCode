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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        int count = 0;
        ListNode *dummy = new ListNode(100000, list1), *traverse = list1;

        while(traverse) {
            if(count == a-1) {
                break;
            }
            count++;
            traverse = traverse->next;
        }

        ListNode *to_remove = traverse->next;
        traverse->next = list2;

        while(traverse->next) {
            traverse = traverse->next;
        }
        
        traverse->next = to_remove;
        ListNode *prev = traverse;
        traverse = to_remove;

        while(traverse && count < b) {
            count++;
            ListNode *to_delete = traverse;
            prev->next = traverse->next;
            traverse = traverse->next;
            delete(to_delete);
        }

        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
};