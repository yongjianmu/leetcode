#include "../include/header.h"


/*
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* p = new_head;
        while(NULL != p && NULL != p->next)
        {
            while(NULL != p->next && val == p->next->val)
            {
                ListNode* del = p->next;
                p->next = p->next->next;
                delete del;
            }
            p = p->next;
        }

        ListNode* ret = new_head->next;
        delete new_head;
        return ret;
    }
};
