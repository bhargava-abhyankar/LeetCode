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

    ListNode* reverse_list(ListNode* head)
    {
        ListNode* prev = NULL, *cur = head, *next = head;

        while(next) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL){
            return false;
        } else if (head->next == NULL) {
            return true;
        }

        /*
        ListNode* slow = head, *fast = head->next;

        while(fast && fast->next) {
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
        
        delete(dummy);

        ListNode* second_half = slow->next;
        slow->next = NULL;

        second_half = reverse_list(second_half);
        

        slow = head, fast = second_half;
        while(slow && fast && slow->val == fast->val) {
            slow = slow->next;
            fast = fast->next;
        }

        /*Note this condition, if both the list will be exausted its palindrome, or if the first list has one node and other list
          is exausted, then also its palindrome becasue, in case of odd number of nodes, first list will be one node bigger.
        ex : gadag , list1 gad  list2 ga , eventhough d is there, its a palindrome */
        
        if((slow == NULL && fast == NULL) || (slow->next == NULL && fast == NULL)) 
            return true;
        else
            return false;
    }
};