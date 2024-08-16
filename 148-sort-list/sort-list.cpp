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

    void print_list(ListNode* head)
    {
        while(head) {
            cout << head->val << " , " << endl;
            head = head->next;
        } 
    }

    /*
    ListNode* merge_sort(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode(0), *traverse;
        traverse = dummy;

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
        } else {
           traverse->next = list2;
        }

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *slow = head, *fast = head->next;

        while(slow && slow->next && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second_list = slow->next;
        ListNode* first_list = head;
        slow->next = NULL;

        head = merge_sort(sortList(first_list), sortList(second_list));
        return head;
    }
    */

    ListNode* mergeSort(ListNode* l1, ListNode*l2)
    {
	    ListNode* dummy = new ListNode(0);
	    ListNode *traverse = dummy;

	    while(l1 && l2) {
		    if(l1->val < l2->val) {
			    traverse->next = l1;
			    l1 = l1->next;
		    } else {
			    traverse->next = l2;
			    l2 = l2->next;
		    }
		    traverse = traverse->next;
	    }
	
	    if(l1) {
		    traverse->next = l1;
	    } else {
		    traverse->next = l2;
	    }
	
	    return(dummy->next);
    }

    ListNode* sortList(ListNode* head)
    {
	    if(head == NULL || head->next == NULL) {
		    return head;
	    }
	
        /*
	    ListNode* slow = head, *fast = head->next;
	
	    if(fast && fast->next) {
		    slow = slow->next;
		    fast = fast->next->next;
	    }
        */

        ListNode *dummy = new ListNode(1000000, head);
        ListNode *slow = dummy, *fast = dummy;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        delete dummy;
        
	    ListNode *list1 = head;
	    ListNode *list2 = slow->next;
	    slow->next = NULL;
	
	    head = mergeSort(sortList(list1), sortList(list2));
	    return head;
    }
};