#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(NULL == head)
        {
            return;
        }

        int cnt = 1;
        int num = -1;
        ListNode* node = head;
        queue<ListNode*> q;
        stack<ListNode*> s;

        while(NULL != node)
        {
            q.push(node);
            s.push(node);
            node = node->next;
            ++num;
        }

        node = q.front();
        q.pop();

        while(cnt <= num)
        {
            if(0 == cnt % 2)
            {
                node->next = q.front();
                q.pop();
            }
            else
            {
                node->next = s.top();
                s.pop();
            }
            node = node->next;
            ++cnt;
        }

        node->next = NULL;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for(int i = 2; i <= 3; ++i)
    {
        ListNode* node = new ListNode(i);
        p->next = node;
        p = p->next;
    }

    Solution sol;
    sol.reorderList(head);

    p = head;
    while(NULL != p)
    {
        ListNode* del = p;
        p = p->next;
        cout << del->val;
        delete del;
        del = p;
    }
    cout << endl;

    return 0;
}
