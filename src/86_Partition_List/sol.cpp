#include <iostream>
#include <climits>

using namespace std;

/*
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(NULL == head)
        {
            return head;
        }

        ListNode* new_head = new ListNode(INT_MIN);
        new_head->next = head;
        ListNode* p = new_head;
        while(NULL != p->next && p->next->val < x)
        {
            p = p->next;
        }

        if(NULL == p->next)
        {
            ListNode* del = new_head;
            ListNode* ret = new_head->next;
            delete del;
            return ret;
        }

        ListNode* q = p;
        while(NULL != q->next)
        {
            if(q->next->val < x)
            {
                ListNode* tmp = q->next;
                q->next = tmp->next;
                tmp->next = p->next;
                p->next = tmp;
                p  = tmp;
            }
            else
            {
                q = q->next;
            }
        }

        ListNode* del = new_head;
        ListNode* ret = new_head->next;
        delete new_head;
        return ret;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(2);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    int x = 3;
    Solution sol;
    ListNode* result = sol.partition(head, x);

    while(NULL != result)
    {
        ListNode* del = result;
        cout << del->val << ", ";
        result = result->next;
        delete del;
    }
    cout << endl;

    return 0;
}
