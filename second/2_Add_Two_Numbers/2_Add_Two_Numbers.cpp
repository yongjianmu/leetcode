// 2_Add_Two_Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../include/header.h"

/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        if (NULL == p1 && NULL == p2)
        {
            return NULL;
        }
        else if (NULL == p1)
        {
            return l2;
        }
        else if (NULL == p2)
        {
            return l1;
        }

        int carry = 0;
        while (NULL != p1->next || NULL != p2->next)
        {
            if (p1 != p2)
            {
                if (NULL == p1->next && NULL != p2->next)
                {
                    p1->next = p2->next;
                }
                else if (NULL != p1->next && NULL == p2->next)
                {
                    p2->next = p1->next;
                }

                int x = p1->val + p2->val + carry;
                carry = 0;
                if (10 <= x)
                {
                    carry = 1;
                    x %= 10;
                }
                p1->val = x;
                p1 = p1->next;
                p2 = p2->next;
            }
            else
            {
                int x = p1->val + carry;
                carry = 0;
                if (10 <= x)
                {
                    carry = 1;
                    x %= 10;
                }
                p1->val = x;
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        if (p1 == p2)
        {
            int x = p1->val + carry;
            carry = 0;
            if (10 <= x)
            {
                carry = 1;
                x %= 10;
            }
            p1->val = x;
        }
        else
        {
            int x = p1->val + p2->val + carry;
            carry = 0;
            if (10 <= x)
            {
                carry = 1;
                x %= 10;
            }
            p1->val = x;
        }
        

        if (1 == carry)
        {
            ListNode* node = new ListNode(carry);
            p1->next = node;
        }

        return head;
    }
};

int main()
{
    vector<int> v1 = { 5 };
    vector<int> v2 = { 5 };

    ListNode* l1 = new ListNode(v1[0]);
    ListNode* p1 = l1;
    for (int i = 1; i < v1.size(); ++i)
    {
        ListNode* node = new ListNode(v1[i]);
        p1->next = node;
        p1 = p1->next;
    }

    ListNode* l2 = new ListNode(v2[0]);
    ListNode* p2 = l2;
    for (int i = 1; i < v2.size(); ++i)
    {
        ListNode* node = new ListNode(v2[i]);
        p2->next = node;
        p2 = p2->next;
    }

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);
    cout << "#### Result ####" << endl;
    p1 = result;
    while (NULL != p1)
    {
        ListNode* del = p1;
        p1 = p1->next;
        cout << del->val << ", ";
        delete del;
    }
    cout << endl;

    return 0;
}

