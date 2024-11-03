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

    /* First traverse the list using two pointer. then slow pointer will be in middle. cut it from the list. take other half list
       and reverse it. then again use two pointer and merge them into single list */

    void print_list(ListNode* head)
    {
        while(head) {
            cout << head->val << " , " << endl;
            head = head->next;
        } 
    }

    ListNode* reverse_list(ListNode* head)
    {
        ListNode *prev = NULL, *cur = head, *next = head;

        while(next) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    ListNode* merge_list(ListNode* list1, ListNode* list2)
    {
        ListNode *l1_cur = list1;
        ListNode *l2_cur = list2;

        while(l1_cur && l2_cur) {
            ListNode *l1_next = l1_cur->next;
            ListNode *l2_next = l2_cur->next;

            l1_cur->next = l2_cur;
            l2_cur->next = l1_next;

            l1_cur = l1_next;
            l2_cur = l2_next;
        }

        return list1;   
    }

    void reorderList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return;

        /*
        ListNode *slow = head, *fast = head->next;

        while(slow && slow->next && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        */

        ListNode *dummy = new ListNode(-1, head);
        ListNode *traverse = dummy;
        ListNode *slow = dummy, *fast = dummy;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        /* delete dummy;

        ListNode *list_two_head = reverse_list(slow->next);
        slow->next = NULL;
        
        merge_list(head, list_two_head);

        */

        ListNode *list1 = head, *list2 = slow->next;
	    slow->next = NULL;
	
	    list2 = reverse_list(list2);

	    while(list1 && list2) {
		    traverse->next = list1;
		    traverse = traverse->next;
		    list1 = list1->next;
	
		    traverse->next = list2;
		    traverse = traverse->next;
		    list2 = list2->next;
	    }
	
        if(list1)
            traverse->next = list1;
        
        if(list2)
            traverse->next = list2;

	    head = dummy->next;
	    delete dummy;
    }
};