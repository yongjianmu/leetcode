#include <vector>
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

int main()
{
    ListNode* l1 = NULL;
    ListNode* l2 = new ListNode(1);
    vector<ListNode*> input;
    input.push_back(l1);
    input.push_back(l2);
    Solution sol;
    ListNode* output = sol.mergeKLists(input);
    return 0;
}
