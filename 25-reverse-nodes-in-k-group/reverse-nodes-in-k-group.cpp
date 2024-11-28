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

    ListNode* reverse_list(ListNode* head, ListNode **tail)
    {
        ListNode *prev = NULL, *cur = head, *next = head;

        while(next) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        *tail = head;
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *traverse = head, *cur_head = head, *cur_tail = NULL;
        int count = 1;
        bool is_first = false;

        while(traverse) {

            if(count == k) {
                ListNode *temp = traverse;
                traverse = traverse->next;
                temp->next = NULL;

                cur_head = reverse_list(cur_head, &cur_tail);
            
                cur_tail->next = traverse;

                if(is_first == false) {
                    is_first = true;
                    head = cur_head;
                }

                count = 1;
                cur_head = traverse;
                cur_tail = NULL;

            } else {
                count++;
                traverse = traverse->next;
            }
        }

        return head;
    }

    */

    ListNode* reverse_list(ListNode* head, ListNode** tail) {
    ListNode *prev = NULL, *cur = head, *next = head;

    while (next) {
        next = next->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    // After reversal, head becomes the tail
    *tail = head;
    return prev; // Return the new head
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *traverse = head, *cur_head = head, *cur_tail = NULL;
    ListNode *prev_tail = NULL; // Track the tail of the previous group
    int count = 0;
    bool is_first = true; // Indicates if it's the first group

    while (traverse) {
        count++;

        if (count == k) {
            ListNode *temp = traverse->next; // Store the next group's head
            traverse->next = NULL; // Detach the current group

            // Reverse the current group
            cur_head = reverse_list(cur_head, &cur_tail);

            if (is_first) {
                // First group becomes the new head
                head = cur_head;
                is_first = false;
            } else {
                // Connect the previous group's tail to the current group's head
                prev_tail->next = cur_head;
            }

            // Update the previous group's tail to the current group's tail
            prev_tail = cur_tail;

            // Move to the next group
            traverse = temp;
            cur_head = temp;
            count = 0; // Reset the count for the new group
        } else {
            traverse = traverse->next;
        }
    }

    // If the number of nodes is not a multiple of k, link the remaining nodes
    if (prev_tail) {
        prev_tail->next = cur_head;
    }

    return head;
}

};