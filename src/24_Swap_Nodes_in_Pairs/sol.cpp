#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(NULL == head || NULL == head->next)
        {
            return head;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        int count = 0;

        while(NULL != curr)
        {
            if(0 == count % 2)
            {
                int tmp = curr->val;
                curr->val = prev->val;
                prev->val = tmp;
            }
            ++count;
            curr = curr->next;
            prev = prev->next;
        }
        return head;
    }
};

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* tail = head;
    for(int i = 1; i < 10; ++i)
    {
        ListNode* tmp_node = new ListNode(i);
        tail->next = tmp_node;
        tail = tail->next;
    }

    Solution sol;
    ListNode* new_head = sol.swapPairs(head);

    tail = new_head;
    while(NULL != new_head)
    {
        cout << tail->val << ",";
        new_head = new_head->next;
        delete tail;
        tail = new_head;
    }
    cout << endl;

    return 0;
}
