/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    /* Note that this is much different than the usual two pointer pattern you are using. here slow and fast both are initialized to same, since we need x and 2x speed
       initializing them to same is nececcery. since they are initialized to same, not at 20 and 21 line we update pointer and then check. if u put it down it wont work.

      Now coming to algo, once slow and fast pointer meet, change one to begining/head and then move them at same pace. they will meet at begining
      

    ListNode *detectCycle(ListNode *head) 
    {
        ListNode * slow = head, *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                slow = head;

                while(fast != slow) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }    
        }

        return NULL;
    }

    */

    /* Same algo as above, but using my universal template of slow and fast pointer */
    
    ListNode *detectCycle(ListNode *head) 
    {
        if(!head)
            return head;
        
        ListNode *dummy = new ListNode(1000000, head);
        ListNode *slow = dummy, *fast = dummy;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                slow = dummy;

                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                delete dummy;
                return slow;
            }
        }

        delete dummy;
        return NULL;
    }

};