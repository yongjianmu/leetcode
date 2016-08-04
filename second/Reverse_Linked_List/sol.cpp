#include "../include/header.h"


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(NULL == head)
        {
            return NULL;
        }

        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* pre = new_head;
        ListNode* p = pre->next;
        ListNode* q = p->next;
        while(NULL != q)
        {
            ListNode* ptr_next = q->next;
            q->next = pre->next;
            pre->next = q;
            q = ptr_next;
        }

        p->next = NULL;
        pre = new_head->next;
        delete new_head;
        return pre;
    }
};

int main()
{
    vector<int> input = {1, 2, 3, 4, 5};
    ListNode* head = createList(input);
    Solution sol;
    ListNode* result = sol.reverseList(head);
    printResult();
    deleteList(result, true);

    return 0;
}
