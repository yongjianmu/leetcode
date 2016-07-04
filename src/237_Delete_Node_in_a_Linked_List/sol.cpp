#include "../include/header.h"

/*
   Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function. 
*/



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* p = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete p;
    }
};
