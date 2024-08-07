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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        if(head == NULL) {
            return ans;
        }

        ListNode *traverse = head;
        int row_start = 0, col_start = 0, row_end = m-1, col_end = n-1;

        while(traverse && row_start <= row_end && col_start <= col_end) {

            for(int j = col_start; j <= col_end && traverse; j++) {
                ans[row_start][j] = traverse->val;
                traverse = traverse->next;
            }
            row_start++;

            for(int i = row_start; i <= row_end && traverse; i++) {
                ans[i][col_end] = traverse->val;
                traverse = traverse->next;
            }
            col_end--;

            if(row_start <= row_end) {
                for(int j = col_end; j >= col_start && traverse; j--) {
                    ans[row_end][j] = traverse->val;
                    traverse = traverse->next;
                }
            }
            row_end--;

            if(col_start <= col_end) {
                for(int i = row_end; i >= row_start && traverse ; i--) {
                    ans[i][col_start] = traverse->val;
                    traverse = traverse->next;
                }
            }
            col_start++;
        }

        return ans;
    }
};