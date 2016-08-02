#include "../include/header.h"


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(NULL == head)
        {
            return false;
        }

        ListNode* x = head, * y = head;

        while(NULL != y->next && NULL != y->next->next)
        {
            y = y->next->next;
            x = x->next;

            if(y == x)
            {
                return true;
            }
        }

        return false;
    }
};
