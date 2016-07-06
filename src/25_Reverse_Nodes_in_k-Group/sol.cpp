#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* tail = head;
        vector<ListNode*> swap_ptr;

        for(int i = 0; i < k; ++i)
        {
            if(NULL == tail)
            {
                return head;
            }
            tail = tail->next;

            swap_ptr.push_back(NULL);
            swap_ptr[i] = head;
            for(int j = 0; j < i; ++j)
            {
                swap_ptr[i] = swap_ptr[i]->next;
            }
        }

        int count = 0;
        while(true)
        {
            if(NULL == swap_ptr[k - 1])
            {
                break;
            }

            if(0 == count % k)
            {
                int begin = 0;
                int end = k - 1;
                while(begin < end)
                {
                    int tmp = swap_ptr[end]->val;
                    swap_ptr[end]->val = swap_ptr[begin]->val;
                    swap_ptr[begin]->val = tmp;
                    ++begin;
                    --end;
                }
            }

            for(int i = 0; i < k; ++i)
            {
                swap_ptr[i] = swap_ptr[i]->next;
            }
            ++count;
        }

        return head;
    }
};

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* tail = head;
    int step = 3;

    for(int i = 1; i < 10; ++i)
    {
        ListNode* tmp_node = new ListNode(i);
        tail->next = tmp_node;
        tail = tail->next;
    }

    Solution sol;
    ListNode* new_head = sol.reverseKGroup(head, step);
    tail = new_head;
    cout << "********** Result **********" << endl;
    while(NULL != new_head)
    {
        new_head = new_head->next;
        cout << tail->val << ",";
        delete tail;
        tail = new_head;
    }
    cout << endl;

    return 0;
}
