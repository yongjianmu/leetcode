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
        ListNode* q = head;
        ListNode* tmp = NULL;
        while(NULL != q->next)
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }

        pre = new_head->next;
        delete new_head;
        return pre;
    }

    ListNode* reverseRecursive(ListNode* head)
    {
        if(NULL == head || NULL == head->next)
        {return head;}

        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
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
