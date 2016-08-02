#include "../include/header.h"


/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.
*/


class Solution {
public:
    ListNode* cmp(ListNode* A, ListNode* B)
    {
        while(NULL != A && NULL != B)
        {
            if(A == B)
            {
                return A;
            }
            A = A->next;
            B = B->next;
        }
        return NULL;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cntA = 0, cntB = 0;
        ListNode* A = headA, * B = headB;
        while(NULL != A)
        {
            ++cntA;
            A = A->next;
        }
        while(NULL != B)
        {
            ++cntB;
            B = B->next;
        }

        A = headA;
        B = headB;
        if(cntA > cntB)
        {
            while(cntA > cntB)
            {
                A = A->next;
                --cntA;
            }
        }
        else if(cntA < cntB)
        {
            while(cntA < cntB)
            {
                B = B->next;
                --cntB;
            }
        }

        return cmp(A, B);
    }
};
