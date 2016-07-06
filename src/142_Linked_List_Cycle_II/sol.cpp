#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(NULL == head)
        {
            return false;
        }

        ListNode* p = head;
        ListNode* q = head;

        while(NULL != q->next && NULL != q->next->next)
        {
            p = p->next;
            q = q->next->next;

            if(p == q)
            {
                break;
            }
        }

        if(NULL == q->next || NULL == q->next->next)
        {
            return NULL;
        }

        p = head;
        while(p != q)
        {
            p = p->next;
            q = q->next;
        }

        return p;
    }
};
