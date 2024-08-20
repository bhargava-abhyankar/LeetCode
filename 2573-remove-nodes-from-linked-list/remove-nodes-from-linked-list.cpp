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
    /* method 1: time O(n) and space O(n) 

    ListNode* removeNodes(ListNode* head) 
    {
        stack<pair<ListNode*, ListNode*>> st;      // prev and cur
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy, *traverse = head;

        while(traverse) {
            st.push({prev, traverse});
            prev = traverse;
            traverse = traverse->next;
        }

        int maximum = INT_MIN;

        while(!st.empty()) {
            auto cur = st.top().second;
            auto previous = st.top().first;

            if(cur->val < maximum) {
                previous->next = cur->next;
                delete cur;
            } else {
                maximum = max(maximum, cur->val);
            }
            
            st.pop();
        }

        head = dummy->next;
        delete dummy;
        return head;
    }

    */

    /* method 2: time O(n) and space O(1). 3 pass solution */

    ListNode* reverse_list(ListNode *head)
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

    ListNode* removeNodes(ListNode* head) 
    {
        int max = INT_MIN;
        head = reverse_list(head);
        ListNode *dummy = new ListNode(-1, head);
        ListNode *traverse = head, *traverse_prev = dummy;

        while(traverse) {
            if(traverse->val < max) {
                ListNode *to_delete = traverse;
                traverse_prev->next = traverse->next;
                traverse = traverse->next;
                delete(to_delete);
            } else {
                max = traverse->val;
                traverse_prev = traverse;
                traverse = traverse->next;
            }
        }

        head = reverse_list(dummy->next);
        delete(dummy);
        return head;
    }
};