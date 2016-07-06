#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

typedef struct _ListNode {
    int val;
    struct _ListNode *next;
} ListNode;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        int length = 0;
        ListNode* p = head;
        ListNode* q = p;

        if(NULL == head)
        {
            return NULL;
        }

        while(NULL != p)
        {
            p = p->next;
            ++length;
        }

        p = head;
        q = p;

        while(NULL != p)
        {
            if(length - n == cnt)
            {
                if(0 == cnt)
                {
                    q = p->next;
                    free(p);
                    return q;
                }
                else
                {
                    q->next = p->next;
                    if(NULL != p->next)
                    {
                        p->next = q->next->next;
                    }
                    free(p);
                    break;
                }
            }
            cnt++;
            q = p;
            p = p->next;
        }

        return head;
    }
};

int main()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->val = 1;

	ListNode* node2 = (ListNode*)malloc(sizeof(ListNode));
	node2->val = 2;

	head->next = node2;
	node2->next = NULL;

	Solution sol;
	ListNode* new_head = sol.removeNthFromEnd(head, 1);	

	while(NULL != new_head)
	{
		cout << new_head->val << endl;
		new_head = new_head->next;
	}

	return 0;
}
