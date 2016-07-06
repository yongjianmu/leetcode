#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
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
                return true;
            }
        }
        return false;
    }
};
