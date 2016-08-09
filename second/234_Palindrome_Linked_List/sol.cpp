#include "../include/header.h"


class Solution {
public:

    void check(ListNode* tail, ListNode*& head, bool& flag)
    {
        if(!flag)
        {
            return;
        }

        if(NULL != tail->next)
        {
            check(tail->next, head, flag);
        }

        if(tail->val != head->val)
        {
            //cout << tail->val << ", " << head->val << endl;
            flag = false;
            return;
        }
        head = head->next;
    }

    bool isPalindrome(ListNode* head) {
        if(NULL == head)
        {
            return true;
        }

        ListNode* new_head = head, * tail = head;
        bool flag = true;
        check(tail, new_head, flag);
        return flag;
    }
};

int main()
{
    vector<int> input = {1, 2, 1, 2};
    ListNode* head = createList(input);
    Solution sol;
    bool result = sol.isPalindrome(head);
    printResult();
    cout << result << endl;

    return 0;
}
