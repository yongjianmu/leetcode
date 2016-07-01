#include "../include/header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(NULL == head)
        {
            return NULL;
        }

        stack<ListNode*> st;
        ListNode* p = head;
        while(NULL != p)
        {
            st.push(p);
            p = p->next;
        }

        ListNode* new_head = new ListNode(-1);
        p = new_head;
        while(!st.empty())
        {
            p->next = st.top();
            st.pop();
            p = p->next;
        }

        p->next = NULL;
        p = new_head->next;
        delete new_head;
        return p;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for(int i = 2; i < 10; ++i)
    {
        ListNode* node = new ListNode(i);
        p->next = node;
        p = p->next;
    }

    Solution sol;
    ListNode* new_head = sol.reverseList(head);
    cout << "#### Result ####" << endl;
    p = new_head;
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
