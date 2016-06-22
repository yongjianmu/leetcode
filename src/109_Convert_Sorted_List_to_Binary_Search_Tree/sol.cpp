#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* solve(ListNode* head, int left, int right)
    {
        if(left == right)
        {
            return new TreeNode(head->val);
        }

        if(left > right)
        {
            return NULL;
        }

        int mid = (left + right) >> 1;
        int cnt = left;
        ListNode* tmp = head;
        while(cnt < mid)
        {
            tmp = tmp->next;
            ++cnt;
        }

        TreeNode* root = new TreeNode(tmp->val);
        root->left = solve(head, left, mid - 1);
        root->right = solve(tmp->next, mid + 1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(NULL == head)
        {
            return NULL;
        }

        int len = 0;
        ListNode* p = head;
        while(NULL != p)
        {
            ++len;
            p = p->next;
        }

        return solve(head, 0, len - 1);
    }
};
