#include "../include/header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* ret = new ListNode(0);
        ListNode* tail = ret;

        if(NULL == l1 && NULL == l2)
        {
            return NULL;
        }

        while(NULL != l1 && NULL != l2)
        {
            if(l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = NULL == l1? l2 : l1;
        return ret->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int size = lists.size();
        if(0 == size)
        {
            return NULL;
        }

        int end = size - 1;

        while(end > 0)
        {
            int begin = 0;
            while(begin < end)
            {
                lists[begin] = mergeTwoLists(lists[begin], lists[end]);
                ++begin;
                --end;
            }
        }

        return lists[0];
    }
};

int main() {
    ListNode* h1 = new ListNode(1);
    vector<ListNode*> vec;
    vec.push_back(h1);
    Solution sol;
    ListNode* result = sol.mergeKLists(vec);
    cout << "#### Result ####" << endl;
    ListNode* p = result;
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