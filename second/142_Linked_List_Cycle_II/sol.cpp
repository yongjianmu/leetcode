#include "../include/header.h"


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(NULL == head)
        {
            return NULL;
        }

        ListNode* x = head, * y = head;
        bool cycle_flag = false;

        while(NULL != y->next && NULL != y->next->next)
        {
            y = y->next->next;
            x = x->next;

            if(x == y)
            {
                cycle_flag = true;
                break;
            }
        }

        if(!cycle_flag)
        {
            return NULL;
        }

        y = head;
        while(x != y)
        {
            y = y->next;
            x = x->next;
        }

        return y;
    }
};
