#include "../include/header.h"

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
 Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverse(ListNode *pre, ListNode *end){
        if(pre == NULL || pre->next == NULL){
            return pre;
        }
        ListNode *p = pre->next;
        ListNode *q = p->next;
        while(q != end){
            ListNode *next = q->next;
            q->next = pre->next;
            pre->next = q;
            q = next;
        }
        p->next = end;
        return p;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        int cnt = 0;
        ListNode *pre = new_head;
        ListNode *cur = head;

        while(cur != NULL){
            cnt++;
            ListNode *next = cur->next;
            if(cnt == k){
                pre = reverse(pre, next);
                cnt = 0;
            }
            cur = next;
        }
        return new_head->next;
    }
};

int main() {
    cout << "#### Result ####" << endl;
    return 0;
}