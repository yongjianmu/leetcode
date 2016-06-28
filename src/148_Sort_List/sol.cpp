#include <iostream>
#include <climits>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* merge(ListNode* lhead, ListNode* rhead)
    {
        ListNode* head = new ListNode(INT_MIN);
        ListNode* p = NULL, * prep = head;
        while(NULL != lhead && NULL != rhead)
        {
            if(lhead->val < rhead->val)
            {
                p = lhead;
                lhead = lhead->next;
            }
            else
            {
                p = rhead;
                rhead = rhead->next;
            }
            prep->next = p;
            prep = prep->next;
        }

        while(NULL != lhead)
        {
            p = lhead;
            lhead = lhead->next;
            prep->next = p;
            prep = prep->next;
        }

        while(NULL != rhead)
        {
            p = rhead;
            rhead = rhead->next;
            prep->next = p;
            prep = prep->next;
        }

        ListNode* ret = head->next;
        delete head;
        return ret;
    }

    ListNode* sortList(ListNode* head) {
        if(NULL == head || NULL == head->next)
        {
            return head;
        }

        ListNode* new_head = new ListNode(INT_MIN);
        new_head->next = head;

        ListNode* p = new_head;
        ListNode* left = head;
        ListNode* right = head; // right is a counter

        while(NULL != right && NULL != right->next)
        {
            p = left;
            left = left->next;
            right = right->next->next;
        }

        p->next = NULL;
        ListNode* lhead = sortList(head);
        ListNode* rhead = sortList(left);
    
        delete new_head;
        return merge(lhead, rhead);
    }
};
