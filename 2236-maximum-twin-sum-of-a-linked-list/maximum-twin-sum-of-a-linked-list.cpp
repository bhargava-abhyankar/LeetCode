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

    int pairSum(ListNode* head) 
    {
        int ans = INT_MIN;
        ListNode *dummy = new ListNode(-1, head), *fast = dummy, *slow = dummy;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *list2_head = reverse_list(slow->next), *list1_traverse = dummy->next, *list2_traverse = list2_head;
        slow->next = NULL;

        while(list1_traverse && list2_traverse) {
            ans = max(ans, list1_traverse->val + list2_traverse->val);
            list1_traverse = list1_traverse->next;
            list2_traverse = list2_traverse->next;
        }

        slow->next = reverse_list(list2_head);
        head = dummy->next;
        delete dummy;
        return ans;
    }
};