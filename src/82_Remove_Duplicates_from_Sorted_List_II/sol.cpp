#include <iostream>
#include <unordered_map>

using namespace std;


/*
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

        ListNode* p = new ListNode(-999);
        ListNode* q;

        p->next = head;
        head = p;
        q = head->next;

        while(NULL != q)
        {
            bool flag = false;
            while(NULL != q->next && q->val == q->next->val)
            {
                ListNode* del = q;
                q = q->next;
                delete del;
            }

            if(p->next == q)
            {
                p = q;
            }
            else
            {
                if(NULL != q)
                {
                    p->next = q->next;
                    flag = true;
                }
            }

            if(NULL != q)
            {
                if(flag)
                {
                    ListNode* del = q;
                    q = q->next;
                    delete del;
                }
                else
                {
                    q = q->next;
                }
            }
        }

        if(NULL != head)
        {
            ListNode* del = head;
            head = head->next;
            delete del;
        }
        return head;
    }
};
