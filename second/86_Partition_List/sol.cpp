#include "../include/header.h"

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(NULL == head)
        {
            return NULL;
        }

        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* small = new_head;
        ListNode* equal = head;

        while(NULL != equal->next && x > equal->val)
        {
            equal = equal->next;
        }

        if(NULL == equal || NULL == equal->next)
        {
            delete new_head;
            return head;
        }
        //cout << equal->val << endl;

        /* Find the first node equal or greater than x in the left */
        while(NULL != small->next && x != small->next->val)
        {
            if(x > small->next->val)
            {
                small = small->next;
            }
            else
            {
                break;
            }
        }
        //cout << small->val << endl;

        /* Find the node less than x in the right */
        ListNode* p = equal;
        while(NULL != p && NULL != p->next)
        {
            if(x > p->next->val)
            {
                //cout << "swap" << endl;
                ListNode* tmp_s = small->next;
                ListNode* tmp_e = p->next;
                small->next = tmp_e;
                p->next = tmp_e->next;
                tmp_e->next = tmp_s;
                small = small->next;
                //p = p->next;
            }
            else
            {
                p = p->next;
            }
        }
        
        p = new_head->next;
        delete new_head;
        return p;
    }
};

int main()
{
    vector<int> input = {1, 4, 3, 2, 5, 2};
    int value = 3;
    //vector<int> input = {3, 1, 2};
    //int value = 3;
    ListNode* head = createList(input);
    Solution sol;
    ListNode* result = sol.partition(head, value);
    printResult();
    deleteList(result, true);

    return 0;
}
