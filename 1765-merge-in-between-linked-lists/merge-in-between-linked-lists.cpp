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
    */

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
{
	ListNode *dummy = new ListNode(-1, list1), *traverse = dummy;
	
	for(int i = 0; i < a; i++) {
		traverse = traverse->next;
	}
	
	ListNode *remaining = traverse->next;
	traverse->next = list2;
	
	while(traverse->next) {
		traverse = traverse->next;
	}

	ListNode *traverse2 = remaining;
	for(int i = a; i <=b; i++) {
		ListNode *temp = traverse2;
		traverse2 = traverse2->next;
		delete temp;
	}
	
	traverse->next = traverse2;
	list1 = dummy->next;
	delete dummy;
	return list1;
}

};