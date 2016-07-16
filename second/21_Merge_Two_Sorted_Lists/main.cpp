#include "../include/header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* new_head = new ListNode(-1);
        ListNode* p = new_head, * p1 = l1, * p2 = l2;
        while(NULL != p1 && NULL != p2)
        {
            if(p1->val <= p2->val)
            {
                p->next = p1;
                p = p->next;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p = p->next;
                p2 = p2->next;
            }
        }

        if(NULL != p1)
        {
            p->next = p1;
            p = p->next;
            p1 = p1->next;
        }
        if(NULL != p2)
        {
            p->next = p2;
            p = p->next;
            p2 = p2->next;
        }

        p = new_head->next;
        delete new_head;
        return p;
    }
};

int main() {
    cout << "#### Result ####" << endl;
    return 0;
}