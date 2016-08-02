#include "../include/header.h"


/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/


class Solution {
public:
    void reorderList(ListNode* head) {
        int cnt = 0;
        ListNode* p = head;
        while(NULL != p)
        {
            p = p->next;
            ++cnt;
        }
        if(3 > cnt)
        {
            return;
        }

        int start = (cnt >> 1) + 1;
        stack<ListNode*> st;
        p = head;
        for(int i = 0; i < cnt; ++i)
        {
            if(i >= start)
            {
                st.push(p);
            }
            p = p->next;
        }

        p = head;
        ListNode* q = p->next;
        while(!st.empty())
        {
            ListNode* node = st.top();
            st.pop();
            p->next = node;
            node->next = q;

            if(st.empty())
            {
                if(0 == cnt % 2)
                {
                    q = q->next;
                }
                q->next = NULL;
            }
            else
            {
                p = q;
                q = q->next;
            }
        }
    }
};
