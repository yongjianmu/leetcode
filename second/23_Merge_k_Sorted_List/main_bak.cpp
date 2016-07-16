#include "../include/header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class mycomparison
{
public:
    bool operator() (const ListNode* lhs, ListNode* rhs) const
    {
        return (lhs->val <= rhs->val);
    }
};

class Solution {
public:
    typedef priority_queue<ListNode*, vector<ListNode*>, mycomparison> myqueue;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(0 == size)
        {
            return NULL;
        }
        ListNode* new_head = new ListNode(-1);
        ListNode* p = new_head;
        myqueue q;
        vector<ListNode*> heads(size);
        for(int i = 0; i < size; ++i)
        {
            heads[i] = lists[i];
            q.push(heads[i]);
        }

        while(!q.empty())
        {
            for(int i = 0; i < size; ++i)
            {
                if(heads[i] == q.top() && NULL != heads[i])
                {
                    heads[i] = heads[i]->next;
                    if(NULL != heads[i])
                    {
                        q.push(heads[i]);
                    }
                }
            }
            p->next = q.top();
            p = p->next;
            q.pop();
        }
        p = new_head->next;
        delete new_head;
        return p;
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