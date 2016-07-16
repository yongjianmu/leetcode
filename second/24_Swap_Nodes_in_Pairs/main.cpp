#include "../include/header.h"

/*
 Given 1->2->3->4, you should return the list as 2->1->4->3.
 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(NULL == head || NULL == head->next)
        {
            return head;
        }
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* front = head;
        ListNode* rear = new_head;
        while(NULL != front && NULL != front->next)
        {
            ListNode* tmp = front->next;
            rear->next = tmp;
            front->next = tmp->next;
            tmp->next = front;

            rear = front;
            front = front->next;
        }

        front = new_head->next;
        delete new_head;
        return front;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for(int i = 2; i <=4; ++i)
    {
        ListNode* node = new ListNode(i);
        p->next = node;
        p = p->next;
    }

    Solution sol;
    ListNode* result = sol.swapPairs(head);
    cout << "#### Result ####" << endl;
    p = result;
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