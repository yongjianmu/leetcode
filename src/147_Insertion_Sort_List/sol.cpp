#include <iostream>
#include <climits>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(NULL == head)
        {
            return head;
        }

        ListNode* new_head = new ListNode(INT_MIN);
        new_head->next = head;
        ListNode* tail = head;

        while(NULL != tail && NULL != tail->next)
        {
            if(tail->next->val < tail->val) // Need swap
            {
                ListNode* node = new_head;
                while(true)
                {
                    if(node->next->val > tail->next->val) // swap
                    {
                        ListNode* tmp = tail->next;
                        tail->next = tail->next->next;
                        tmp->next = node->next;
                        node->next = tmp;
                        break;
                    }
                    node = node->next;
                }
            }
            else
            {
                tail = tail->next;
            }
        }

        ListNode* ret = new_head->next;
        delete new_head;
        return ret;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for(int i = 2; i <= 9; ++i)
    {
        ListNode* node = new ListNode(i);
        p->next = node;
        p = p->next;
    }
    ListNode* q = new ListNode(0);
    p->next = q;

    cout << "Original List" << endl;
    p = head;
    while(NULL != p)
    {
        cout << p->val << ", ";
        p = p->next;
    }
    cout << endl;

    cout << "#### Result ####" << endl;
    Solution sol;
    ListNode* result = sol.insertionSortList(head);
    p = result;
    while(NULL != p)
    {
        ListNode* del = p;
        p = p->next;
        cout << del->val << ", ";
    }
    cout << endl;

    return 0;
}
