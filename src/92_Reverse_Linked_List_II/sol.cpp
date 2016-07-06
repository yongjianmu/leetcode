#include <iostream>
#include <stack>

using namespace std;

/*
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m >= n)
        {
            return head;
        }

        stack<ListNode*> st;
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* p = new_head;
        ListNode* q = head;
        int cnt = 1;

        for(cnt = 1; cnt <= n; ++cnt)
        {
            if(m <= cnt)
            {
                st.push(q);
                ListNode* del = q;
                q = q->next;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }

        while(!st.empty())
        {
            ListNode* node = st.top();
            st.pop();
            p->next = node;
            p = p->next;
        }

        p->next = q;
        q = new_head->next;
        delete new_head;
        return q;
    }
};

int main()
{
    ListNode* head = new ListNode(3);
    ListNode* p = head;
    for(int i = 2; i <= 2; ++i)
    {
        ListNode* node = new ListNode(5);
        p->next = node;
        p = p->next;
    }

    Solution sol;
    ListNode* result = sol.reverseBetween(head, 1, 2);
    p = result;
    while(NULL != p)
    {
        cout << p->val << ", ";
        ListNode* del = p;
        p = p->next;
        delete del;
    }
    cout << endl;

    return 0;
}
