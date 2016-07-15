#include "../include/header.h"

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(NULL == head)
        {
            return NULL;
        }

        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* p = new_head;
        int cnt = 0;
        while(cnt < n)
        {
            if(NULL == p->next)
            {
                delete new_head;
                return head;
            }
            p = p->next;
            ++cnt;
        }
        ListNode* q = new_head;
        while(NULL != p->next)
        {
            p = p->next;
            q = q->next;
        }

        p = q->next;
        q->next = p->next;
        delete p;


        q = new_head->next;
        delete new_head;
        return q;
    }
};

int main() {
    int target = 2;
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for(int i = 2; i <= 5; ++i)
    {
        ListNode* node = new ListNode(i);
        p->next = node;
        p = p->next;
    }

    p = head;
    while(NULL != p)
    {
        cout << p->val << ", ";
        p = p->next;
    }
    cout << endl;

    Solution sol;
    ListNode* result = sol.removeNthFromEnd(head, target);
    cout << "#### Result ####" << endl;
    p = result;
    while(NULL != p)
    {
        ListNode* del = p;
        cout << del->val << ", ";
        p = p->next;
        delete del;
    }
    cout << endl;

    return 0;
}