#include "../include/header.h"

/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* new_head = new ListNode(-1);
        new_head ->next = head;
        ListNode* p = new_head, * start = new_head;
        int cnt = 0;
        while(cnt < m)
        {
            start = p;
            p = p->next;
            ++cnt;
        }

        ListNode* q = p->next;
        while(cnt < n)
        {
            ListNode* next_q = q->next;
            q->next = start->next;
            start->next = q;
            q = next_q;
            ++cnt;
        }
        p->next = q; 

        ListNode* ret = new_head->next;
        delete new_head;
        return ret;
    }
};

int main()
{
    vector<int> input = {1, 2, 3, 4, 5};
    ListNode* head = createList(input);
    int m = 2, n = 4;
    Solution sol;
    ListNode* result = sol.reverseBetween(head, m, n);
    deleteList(result, true);

    return 0;
}
