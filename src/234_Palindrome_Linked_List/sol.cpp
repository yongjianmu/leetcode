#include "../include/header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sec;
    bool flag;

    bool cmp(int mid, int len, ListNode* start)
    {
        if(mid > 0)
        {
            cmp(mid - 1, len, start->next);
        }

        //cout << mid << endl;
        //cout << start->val << ", " << sec->val << endl;
        if(flag && start->val == sec->val)
        {
            sec = sec->next;
            return true;
        }

        flag = false;
        return false;
    }

    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while(NULL != p)
        {
            ++len;
            p = p->next;
        }

        if(1 >= len)
        {
            return true;
        }

        int mid = (len >> 1) - 1;
        int tmp = 0 == len % 2 ? mid + 1 : mid + 2;
        //cout << mid << ", " << tmp << endl;
        int cnt = 0;
        p = head;
        while(cnt < tmp)
        {
            p = p->next;
            ++cnt;
        }
        sec = p;
        flag = true;
        return cmp(mid, len, head);
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

    for(int i = 9; i >= 1; --i)
    {
        ListNode* node = new ListNode(i);
        p->next = node;
        p = p->next;
    }

    p = head;
    while(NULL != p)
    {
        cout << p->val << ", ";
        p = p->next;
    }
    cout << endl;

    Solution sol;
    bool result = sol.isPalindrome(head);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    p = head;
    while(NULL != p)
    {
        ListNode* del = p;
        p = p->next;
        delete del;
    }

    return 0;
}
