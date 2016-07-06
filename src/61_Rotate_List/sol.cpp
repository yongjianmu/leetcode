#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(0 == k || NULL == head)
        {
            return head;
        }

        ListNode* p = head;
        ListNode* pri = head;
        ListNode* tail = NULL;
        int cnt = 1;
        while(NULL != p->next)
        {
            if(cnt < k)
            {
                p = p->next;
                ++cnt;
                continue;
            }

            tail = pri;
            pri = pri->next;
            p = p->next;
        }

        if(NULL != tail)
        {
            p->next = head;
            tail->next = NULL;
        }
        return pri;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* tail = head;

    for(int i = 2; i < 6; ++i)
    {
        ListNode* node = new ListNode(i);
        tail->next = node;
        tail = tail->next;
    }

    int k = 2;
    Solution sol;
    ListNode* new_head = sol.rotateRight(head, k);

    while(NULL != new_head)
    {
        cout << new_head->val << ", ";
        ListNode* del = new_head;
        new_head = new_head->next;
        delete del;
    }
    cout << endl;

    return 0;
}
