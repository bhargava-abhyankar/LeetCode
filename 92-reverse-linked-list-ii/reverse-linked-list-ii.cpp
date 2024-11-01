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
    void reverse_list(ListNode *cur, ListNode **head_to_link, ListNode **remaining_to_link, int left, int right)
    {
        ListNode *prev = NULL, *next = cur;

        while(left <= right) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            left++;
        }

        *head_to_link = prev;
        *remaining_to_link = cur;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode *dummy = new ListNode(-1000, head);
        ListNode *traverse = dummy;

        for(int i = 0; i < left-1; i++) {
            traverse = traverse->next;
        }

        ListNode *head_to_link = NULL, *remaining_to_link = NULL; 
        reverse_list(traverse->next, &head_to_link, &remaining_to_link, left, right);

        traverse->next->next = remaining_to_link;
        traverse->next = head_to_link;
        ListNode *new_head = dummy->next;
        delete(dummy);
        return new_head;

        return head;
    }

    */

    /* Same as above, just better naming convention */

    void reverse_in_range(ListNode *head, ListNode **reversed_head, ListNode **remaining_nodes_head, int left, int right)
    {
	    ListNode *prev = NULL, *cur = head, *next = head;
	
	    while(next && left <= right) {
            next = next->next;  
		    cur->next = prev;
		    prev = cur;
		    cur = next;
		    left++;
	    }

	    *reversed_head = prev;
	    *remaining_nodes_head = cur;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
	    ListNode *dummy = new ListNode(-1, head);
	    ListNode *traverse = dummy;
	
	    for(int i = 0; i < left-1; i++) {
		    traverse = traverse->next;
	    }
	
	    ListNode *reversed_head, *remaining_nodes_head;
	    reverse_in_range( traverse->next, &reversed_head, &remaining_nodes_head, left, right);
	
	    traverse->next->next = remaining_nodes_head;
	    traverse->next = reversed_head;

	    head = dummy->next;
	    delete dummy;
	    return head;
    }
};