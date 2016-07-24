#include "../include/header.h"

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(NULL == head || NULL == head->next)
        {
            return head;
        }

        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* p = new_head, * qh = head, *qt = head;
        bool flag = false;
        while(NULL != qt)
        {
            if(qh == qt)
            {
                if(NULL == qt->next)
                {
                    break;
                }
                qt = qt->next;
                continue;
            }

            if(qh->val != qt->val)
            {
                if(flag)
                {
                    p->next = qt;
                    while(qt != qh)
                    {
                        ListNode* del = qh;
                        qh = qh->next;
                        delete del;
                    }
                    qh = qt;
                    flag = false;
                }
                else
                {
                    qh = qh->next;
                    p = p->next;
                }
                continue;
            }
            else
            {
                if(NULL == qt)
                {
                    if(flag)
                    {
                        p->next = NULL;
                        while(NULL != qh)
                        {
                            ListNode* del = qh;
                            qh = qh->next;
                            delete del;
                        }
                    }
                    break;
                }

                flag = true;
                if(NULL == qt->next)
                {
                    p->next = NULL;
                    while(NULL != qh)
                    {
                        ListNode* del = qh;
                        qh = qh->next;
                        delete del;
                    }
                    break;
                }
                else
                {
                    qt = qt->next;
                }
            }
        }
        ListNode* ret = new_head->next;
        delete new_head;
        return ret;
    }
};

int main()
{
    vector<int> value = {1,1};
    ListNode* head = new ListNode(value[0]);
    ListNode* p = head;
    for(int i = 1; i < value.size(); ++i)
    {
        ListNode* node = new ListNode(value[i]);
        p->next = node;
        p = p->next;
    }

    Solution sol;
    ListNode* result = sol.deleteDuplicates(head);
    cout << "#### Result ####" << endl;
    p = result;
    while(NULL != p)
    {
        ListNode* del = p;
        p = p->next;
        cout << del->val << ", ";
        delete del;
    }
    cout << endl;

    return 0;
}
